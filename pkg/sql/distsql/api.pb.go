// Code generated by protoc-gen-gogo.
// source: cockroach/pkg/sql/distsql/api.proto
// DO NOT EDIT!

/*
	Package distsql is a generated protocol buffer package.

	It is generated from these files:
		cockroach/pkg/sql/distsql/api.proto
		cockroach/pkg/sql/distsql/data.proto
		cockroach/pkg/sql/distsql/processors.proto

	It has these top-level messages:
		SetupFlowRequest
		SimpleResponse
		Expression
		Ordering
		MailboxSpec
		StreamEndpointSpec
		InputSyncSpec
		OutputRouterSpec
		DatumInfo
		StreamHeader
		StreamData
		StreamTrailer
		StreamMessage
		NoopCoreSpec
		TableReaderSpan
		TableReaderSpec
		JoinReaderSpec
		SorterSpec
		EvaluatorSpec
		DistinctSpec
		MergeJoinerSpec
		HashJoinerSpec
		AggregatorSpec
		ProcessorCoreUnion
		ProcessorSpec
		FlowSpec
*/
package distsql

import proto "github.com/gogo/protobuf/proto"
import fmt "fmt"
import math "math"
import cockroach_roachpb1 "github.com/cockroachdb/cockroach/pkg/roachpb"
import cockroach_roachpb2 "github.com/cockroachdb/cockroach/pkg/roachpb"
import cockroach_util_tracing "github.com/cockroachdb/cockroach/pkg/util/tracing"

import (
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

import io "io"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.GoGoProtoPackageIsVersion2 // please upgrade the proto package

type SetupFlowRequest struct {
	Txn cockroach_roachpb1.Transaction `protobuf:"bytes,1,opt,name=txn" json:"txn"`
	// If set, the context of an active tracing span.
	TraceContext *cockroach_util_tracing.SpanContextCarrier `protobuf:"bytes,2,opt,name=trace_context,json=traceContext" json:"trace_context,omitempty"`
	Flow         FlowSpec                                   `protobuf:"bytes,3,opt,name=flow" json:"flow"`
}

func (m *SetupFlowRequest) Reset()                    { *m = SetupFlowRequest{} }
func (m *SetupFlowRequest) String() string            { return proto.CompactTextString(m) }
func (*SetupFlowRequest) ProtoMessage()               {}
func (*SetupFlowRequest) Descriptor() ([]byte, []int) { return fileDescriptorApi, []int{0} }

type SimpleResponse struct {
	// TODO(radu): we should be using our own error instead of roachpb.Error.
	// One important error field for distsql is whether the error is
	// "authoritative": if a query is distributed on multiple nodes and one node
	// hits an error, the other nodes may hit errors as well as a consequence
	// (e.g. streams can't connect to the failed flow). The node that started the
	// flow needs to distinguish which errors are caused by non-availability of
	// other nodes so they don't obscure the real error.
	Error *cockroach_roachpb2.Error `protobuf:"bytes,1,opt,name=error" json:"error,omitempty"`
}

func (m *SimpleResponse) Reset()                    { *m = SimpleResponse{} }
func (m *SimpleResponse) String() string            { return proto.CompactTextString(m) }
func (*SimpleResponse) ProtoMessage()               {}
func (*SimpleResponse) Descriptor() ([]byte, []int) { return fileDescriptorApi, []int{1} }

func init() {
	proto.RegisterType((*SetupFlowRequest)(nil), "cockroach.sql.distsql.SetupFlowRequest")
	proto.RegisterType((*SimpleResponse)(nil), "cockroach.sql.distsql.SimpleResponse")
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion3

// Client API for DistSQL service

type DistSQLClient interface {
	// RunSimpleFlow instantiates a flow and streams back results of that flow.
	// The request must contain one flow, and that flow must have a single mailbox
	// of the special simple response type.
	RunSimpleFlow(ctx context.Context, in *SetupFlowRequest, opts ...grpc.CallOption) (DistSQL_RunSimpleFlowClient, error)
	// SetupFlow instantiates a flow (subgraps of a distributed SQL
	// computation) on the receiving node.
	SetupFlow(ctx context.Context, in *SetupFlowRequest, opts ...grpc.CallOption) (*SimpleResponse, error)
	// FlowStream is used to push a stream of messages that is part of a flow. The
	// first message will have a StreamHeader which identifies the flow and the
	// stream (mailbox).
	FlowStream(ctx context.Context, opts ...grpc.CallOption) (DistSQL_FlowStreamClient, error)
}

type distSQLClient struct {
	cc *grpc.ClientConn
}

func NewDistSQLClient(cc *grpc.ClientConn) DistSQLClient {
	return &distSQLClient{cc}
}

func (c *distSQLClient) RunSimpleFlow(ctx context.Context, in *SetupFlowRequest, opts ...grpc.CallOption) (DistSQL_RunSimpleFlowClient, error) {
	stream, err := grpc.NewClientStream(ctx, &_DistSQL_serviceDesc.Streams[0], c.cc, "/cockroach.sql.distsql.DistSQL/RunSimpleFlow", opts...)
	if err != nil {
		return nil, err
	}
	x := &distSQLRunSimpleFlowClient{stream}
	if err := x.ClientStream.SendMsg(in); err != nil {
		return nil, err
	}
	if err := x.ClientStream.CloseSend(); err != nil {
		return nil, err
	}
	return x, nil
}

type DistSQL_RunSimpleFlowClient interface {
	Recv() (*StreamMessage, error)
	grpc.ClientStream
}

type distSQLRunSimpleFlowClient struct {
	grpc.ClientStream
}

func (x *distSQLRunSimpleFlowClient) Recv() (*StreamMessage, error) {
	m := new(StreamMessage)
	if err := x.ClientStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

func (c *distSQLClient) SetupFlow(ctx context.Context, in *SetupFlowRequest, opts ...grpc.CallOption) (*SimpleResponse, error) {
	out := new(SimpleResponse)
	err := grpc.Invoke(ctx, "/cockroach.sql.distsql.DistSQL/SetupFlow", in, out, c.cc, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *distSQLClient) FlowStream(ctx context.Context, opts ...grpc.CallOption) (DistSQL_FlowStreamClient, error) {
	stream, err := grpc.NewClientStream(ctx, &_DistSQL_serviceDesc.Streams[1], c.cc, "/cockroach.sql.distsql.DistSQL/FlowStream", opts...)
	if err != nil {
		return nil, err
	}
	x := &distSQLFlowStreamClient{stream}
	return x, nil
}

type DistSQL_FlowStreamClient interface {
	Send(*StreamMessage) error
	CloseAndRecv() (*SimpleResponse, error)
	grpc.ClientStream
}

type distSQLFlowStreamClient struct {
	grpc.ClientStream
}

func (x *distSQLFlowStreamClient) Send(m *StreamMessage) error {
	return x.ClientStream.SendMsg(m)
}

func (x *distSQLFlowStreamClient) CloseAndRecv() (*SimpleResponse, error) {
	if err := x.ClientStream.CloseSend(); err != nil {
		return nil, err
	}
	m := new(SimpleResponse)
	if err := x.ClientStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

// Server API for DistSQL service

type DistSQLServer interface {
	// RunSimpleFlow instantiates a flow and streams back results of that flow.
	// The request must contain one flow, and that flow must have a single mailbox
	// of the special simple response type.
	RunSimpleFlow(*SetupFlowRequest, DistSQL_RunSimpleFlowServer) error
	// SetupFlow instantiates a flow (subgraps of a distributed SQL
	// computation) on the receiving node.
	SetupFlow(context.Context, *SetupFlowRequest) (*SimpleResponse, error)
	// FlowStream is used to push a stream of messages that is part of a flow. The
	// first message will have a StreamHeader which identifies the flow and the
	// stream (mailbox).
	FlowStream(DistSQL_FlowStreamServer) error
}

func RegisterDistSQLServer(s *grpc.Server, srv DistSQLServer) {
	s.RegisterService(&_DistSQL_serviceDesc, srv)
}

func _DistSQL_RunSimpleFlow_Handler(srv interface{}, stream grpc.ServerStream) error {
	m := new(SetupFlowRequest)
	if err := stream.RecvMsg(m); err != nil {
		return err
	}
	return srv.(DistSQLServer).RunSimpleFlow(m, &distSQLRunSimpleFlowServer{stream})
}

type DistSQL_RunSimpleFlowServer interface {
	Send(*StreamMessage) error
	grpc.ServerStream
}

type distSQLRunSimpleFlowServer struct {
	grpc.ServerStream
}

func (x *distSQLRunSimpleFlowServer) Send(m *StreamMessage) error {
	return x.ServerStream.SendMsg(m)
}

func _DistSQL_SetupFlow_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(SetupFlowRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(DistSQLServer).SetupFlow(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/cockroach.sql.distsql.DistSQL/SetupFlow",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(DistSQLServer).SetupFlow(ctx, req.(*SetupFlowRequest))
	}
	return interceptor(ctx, in, info, handler)
}

func _DistSQL_FlowStream_Handler(srv interface{}, stream grpc.ServerStream) error {
	return srv.(DistSQLServer).FlowStream(&distSQLFlowStreamServer{stream})
}

type DistSQL_FlowStreamServer interface {
	SendAndClose(*SimpleResponse) error
	Recv() (*StreamMessage, error)
	grpc.ServerStream
}

type distSQLFlowStreamServer struct {
	grpc.ServerStream
}

func (x *distSQLFlowStreamServer) SendAndClose(m *SimpleResponse) error {
	return x.ServerStream.SendMsg(m)
}

func (x *distSQLFlowStreamServer) Recv() (*StreamMessage, error) {
	m := new(StreamMessage)
	if err := x.ServerStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

var _DistSQL_serviceDesc = grpc.ServiceDesc{
	ServiceName: "cockroach.sql.distsql.DistSQL",
	HandlerType: (*DistSQLServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "SetupFlow",
			Handler:    _DistSQL_SetupFlow_Handler,
		},
	},
	Streams: []grpc.StreamDesc{
		{
			StreamName:    "RunSimpleFlow",
			Handler:       _DistSQL_RunSimpleFlow_Handler,
			ServerStreams: true,
		},
		{
			StreamName:    "FlowStream",
			Handler:       _DistSQL_FlowStream_Handler,
			ClientStreams: true,
		},
	},
	Metadata: fileDescriptorApi,
}

func (m *SetupFlowRequest) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SetupFlowRequest) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	dAtA[i] = 0xa
	i++
	i = encodeVarintApi(dAtA, i, uint64(m.Txn.Size()))
	n1, err := m.Txn.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n1
	if m.TraceContext != nil {
		dAtA[i] = 0x12
		i++
		i = encodeVarintApi(dAtA, i, uint64(m.TraceContext.Size()))
		n2, err := m.TraceContext.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n2
	}
	dAtA[i] = 0x1a
	i++
	i = encodeVarintApi(dAtA, i, uint64(m.Flow.Size()))
	n3, err := m.Flow.MarshalTo(dAtA[i:])
	if err != nil {
		return 0, err
	}
	i += n3
	return i, nil
}

func (m *SimpleResponse) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalTo(dAtA)
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SimpleResponse) MarshalTo(dAtA []byte) (int, error) {
	var i int
	_ = i
	var l int
	_ = l
	if m.Error != nil {
		dAtA[i] = 0xa
		i++
		i = encodeVarintApi(dAtA, i, uint64(m.Error.Size()))
		n4, err := m.Error.MarshalTo(dAtA[i:])
		if err != nil {
			return 0, err
		}
		i += n4
	}
	return i, nil
}

func encodeFixed64Api(dAtA []byte, offset int, v uint64) int {
	dAtA[offset] = uint8(v)
	dAtA[offset+1] = uint8(v >> 8)
	dAtA[offset+2] = uint8(v >> 16)
	dAtA[offset+3] = uint8(v >> 24)
	dAtA[offset+4] = uint8(v >> 32)
	dAtA[offset+5] = uint8(v >> 40)
	dAtA[offset+6] = uint8(v >> 48)
	dAtA[offset+7] = uint8(v >> 56)
	return offset + 8
}
func encodeFixed32Api(dAtA []byte, offset int, v uint32) int {
	dAtA[offset] = uint8(v)
	dAtA[offset+1] = uint8(v >> 8)
	dAtA[offset+2] = uint8(v >> 16)
	dAtA[offset+3] = uint8(v >> 24)
	return offset + 4
}
func encodeVarintApi(dAtA []byte, offset int, v uint64) int {
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return offset + 1
}
func (m *SetupFlowRequest) Size() (n int) {
	var l int
	_ = l
	l = m.Txn.Size()
	n += 1 + l + sovApi(uint64(l))
	if m.TraceContext != nil {
		l = m.TraceContext.Size()
		n += 1 + l + sovApi(uint64(l))
	}
	l = m.Flow.Size()
	n += 1 + l + sovApi(uint64(l))
	return n
}

func (m *SimpleResponse) Size() (n int) {
	var l int
	_ = l
	if m.Error != nil {
		l = m.Error.Size()
		n += 1 + l + sovApi(uint64(l))
	}
	return n
}

func sovApi(x uint64) (n int) {
	for {
		n++
		x >>= 7
		if x == 0 {
			break
		}
	}
	return n
}
func sozApi(x uint64) (n int) {
	return sovApi(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *SetupFlowRequest) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowApi
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: SetupFlowRequest: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SetupFlowRequest: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Txn", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowApi
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthApi
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Txn.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TraceContext", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowApi
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthApi
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.TraceContext == nil {
				m.TraceContext = &cockroach_util_tracing.SpanContextCarrier{}
			}
			if err := m.TraceContext.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Flow", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowApi
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthApi
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Flow.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipApi(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthApi
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *SimpleResponse) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowApi
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: SimpleResponse: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SimpleResponse: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Error", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowApi
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthApi
			}
			postIndex := iNdEx + msglen
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.Error == nil {
				m.Error = &cockroach_roachpb2.Error{}
			}
			if err := m.Error.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipApi(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if skippy < 0 {
				return ErrInvalidLengthApi
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func skipApi(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowApi
			}
			if iNdEx >= l {
				return 0, io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		wireType := int(wire & 0x7)
		switch wireType {
		case 0:
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowApi
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				iNdEx++
				if dAtA[iNdEx-1] < 0x80 {
					break
				}
			}
			return iNdEx, nil
		case 1:
			iNdEx += 8
			return iNdEx, nil
		case 2:
			var length int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowApi
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				length |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			iNdEx += length
			if length < 0 {
				return 0, ErrInvalidLengthApi
			}
			return iNdEx, nil
		case 3:
			for {
				var innerWire uint64
				var start int = iNdEx
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return 0, ErrIntOverflowApi
					}
					if iNdEx >= l {
						return 0, io.ErrUnexpectedEOF
					}
					b := dAtA[iNdEx]
					iNdEx++
					innerWire |= (uint64(b) & 0x7F) << shift
					if b < 0x80 {
						break
					}
				}
				innerWireType := int(innerWire & 0x7)
				if innerWireType == 4 {
					break
				}
				next, err := skipApi(dAtA[start:])
				if err != nil {
					return 0, err
				}
				iNdEx = start + next
			}
			return iNdEx, nil
		case 4:
			return iNdEx, nil
		case 5:
			iNdEx += 4
			return iNdEx, nil
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
	}
	panic("unreachable")
}

var (
	ErrInvalidLengthApi = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowApi   = fmt.Errorf("proto: integer overflow")
)

func init() { proto.RegisterFile("cockroach/pkg/sql/distsql/api.proto", fileDescriptorApi) }

var fileDescriptorApi = []byte{
	// 425 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x09, 0x6e, 0x88, 0x02, 0xff, 0x8c, 0x91, 0xcf, 0x8a, 0x13, 0x31,
	0x1c, 0xc7, 0x27, 0xbb, 0x2b, 0x8b, 0xd1, 0x15, 0x09, 0x0a, 0x43, 0x0f, 0xb3, 0xeb, 0xb8, 0xe2,
	0xb2, 0x87, 0x8c, 0x2c, 0x28, 0x78, 0x93, 0xad, 0x7a, 0x52, 0xc4, 0x19, 0x4f, 0x42, 0x29, 0x69,
	0x1a, 0xc7, 0xd0, 0x69, 0x92, 0x26, 0x19, 0xda, 0xc7, 0xf0, 0x3d, 0x7c, 0x91, 0x1e, 0x3d, 0x89,
	0x27, 0xd1, 0xf1, 0x45, 0x24, 0x99, 0xd8, 0x3f, 0xd2, 0x81, 0x9e, 0x26, 0x64, 0x3e, 0xdf, 0x6f,
	0x3e, 0xbf, 0x04, 0x3e, 0xa4, 0x92, 0x4e, 0xb4, 0x24, 0xf4, 0x73, 0xa6, 0x26, 0x65, 0x66, 0x66,
	0x55, 0x36, 0xe6, 0xc6, 0xba, 0x2f, 0x51, 0x1c, 0x2b, 0x2d, 0xad, 0x44, 0xf7, 0x57, 0x10, 0x36,
	0xb3, 0x0a, 0x07, 0xa0, 0x77, 0xb6, 0x9d, 0xf5, 0x2b, 0x35, 0xca, 0xc6, 0xc4, 0x92, 0x36, 0xd8,
	0x4b, 0x77, 0x13, 0x4c, 0x6b, 0xa9, 0x4d, 0x60, 0xce, 0xbb, 0x0d, 0x36, 0x9a, 0x2e, 0xbb, 0x29,
	0xa5, 0x25, 0x65, 0xc6, 0xac, 0x1b, 0x9f, 0x6e, 0xb3, 0xb5, 0xe5, 0x55, 0x66, 0x35, 0xa1, 0x5c,
	0x94, 0x99, 0x51, 0x44, 0x0c, 0xa9, 0x14, 0x96, 0x2d, 0xec, 0x90, 0x12, 0xad, 0x39, 0xd3, 0x21,
	0x76, 0xaf, 0x94, 0xa5, 0xf4, 0xcb, 0xcc, 0xad, 0xda, 0xdd, 0xf4, 0x3b, 0x80, 0x77, 0x0b, 0x66,
	0x6b, 0xf5, 0xba, 0x92, 0xf3, 0x9c, 0xcd, 0x6a, 0x66, 0x2c, 0x7a, 0x06, 0x0f, 0xed, 0x42, 0xc4,
	0xe0, 0x0c, 0x5c, 0xdc, 0xba, 0x4a, 0xf0, 0xfa, 0x7a, 0xc2, 0x84, 0xf8, 0x83, 0x26, 0xc2, 0x10,
	0x6a, 0xb9, 0x14, 0xd7, 0x47, 0xcb, 0x9f, 0xa7, 0x51, 0xee, 0x02, 0xe8, 0x1d, 0x3c, 0x71, 0x22,
	0xec, 0x9f, 0x41, 0x7c, 0xe0, 0x1b, 0x2e, 0x37, 0x1a, 0x9c, 0x2d, 0x0e, 0xb6, 0xb8, 0x50, 0x44,
	0xf4, 0x5b, 0xb4, 0xdf, 0xba, 0xe6, 0xb7, 0x7d, 0x41, 0xd8, 0x44, 0xcf, 0xe1, 0xd1, 0xa7, 0x4a,
	0xce, 0xe3, 0x43, 0xdf, 0x73, 0x8a, 0x77, 0x3e, 0x14, 0x76, 0xea, 0x85, 0x62, 0x34, 0xa8, 0xf8,
	0x48, 0xfa, 0x02, 0xde, 0x29, 0xf8, 0x54, 0x55, 0x2c, 0x67, 0x46, 0x49, 0x61, 0x18, 0xc2, 0xf0,
	0x86, 0x7f, 0x99, 0x30, 0x57, 0xbc, 0x63, 0xae, 0x57, 0xee, 0x7f, 0xde, 0x62, 0x57, 0x5f, 0x0f,
	0xe0, 0xf1, 0x4b, 0x6e, 0x6c, 0xf1, 0xfe, 0x0d, 0x1a, 0xc1, 0x93, 0xbc, 0x16, 0x6d, 0xa1, 0x3b,
	0x0e, 0x3d, 0xee, 0x70, 0xf9, 0xff, 0x2e, 0x7b, 0xe7, 0x5d, 0xa0, 0xd5, 0x8c, 0x4c, 0xdf, 0x32,
	0x63, 0x48, 0xc9, 0xd2, 0xe8, 0x09, 0x40, 0x03, 0x78, 0x73, 0x95, 0xde, 0xbf, 0xff, 0x51, 0x17,
	0xb8, 0x35, 0x7c, 0x1a, 0xa1, 0x01, 0x84, 0xfe, 0xa2, 0xfc, 0xb9, 0x68, 0x2f, 0xad, 0xbd, 0xcb,
	0x2f, 0xc0, 0xf5, 0x83, 0xe5, 0xef, 0x24, 0x5a, 0x36, 0x09, 0xf8, 0xd6, 0x24, 0xe0, 0x47, 0x93,
	0x80, 0x5f, 0x4d, 0x02, 0xbe, 0xfc, 0x49, 0xa2, 0x8f, 0xc7, 0x21, 0xf5, 0x37, 0x00, 0x00, 0xff,
	0xff, 0xea, 0xf3, 0xd8, 0x8f, 0x8d, 0x03, 0x00, 0x00,
}
