// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cockroach/pkg/storage/engine/enginepb/rocksdb.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "cockroach/pkg/storage/engine/enginepb/rocksdb.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)

namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {

void protobuf_ShutdownFile_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto() {
  SSTUserProperties_default_instance_.Shutdown();
  SSTUserPropertiesCollection_default_instance_.Shutdown();
}

void protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::cockroach::util::hlc::protobuf_InitDefaults_cockroach_2fpkg_2futil_2fhlc_2ftimestamp_2eproto();
  ::google::protobuf::internal::GetEmptyString();
  SSTUserProperties_default_instance_.DefaultConstruct();
  ::google::protobuf::internal::GetEmptyString();
  SSTUserPropertiesCollection_default_instance_.DefaultConstruct();
  SSTUserProperties_default_instance_.get_mutable()->InitAsDefaultInstance();
  SSTUserPropertiesCollection_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_once_);
void protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_once_,
                 &protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_impl);
}
void protobuf_AddDesc_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto();
  ::cockroach::util::hlc::protobuf_AddDesc_cockroach_2fpkg_2futil_2fhlc_2ftimestamp_2eproto();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_once_);
void protobuf_AddDesc_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_once_,
                 &protobuf_AddDesc_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_impl);
}
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto {
  StaticDescriptorInitializer_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto() {
    protobuf_AddDesc_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto();
  }
} static_descriptor_initializer_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto_;
#endif  // GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SSTUserProperties::kPathFieldNumber;
const int SSTUserProperties::kTsMinFieldNumber;
const int SSTUserProperties::kTsMaxFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SSTUserProperties::SSTUserProperties()
  : ::google::protobuf::MessageLite(), _arena_ptr_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:cockroach.storage.engine.enginepb.SSTUserProperties)
}

void SSTUserProperties::InitAsDefaultInstance() {
  ts_min_ = const_cast< ::cockroach::util::hlc::Timestamp*>(
      ::cockroach::util::hlc::Timestamp::internal_default_instance());
  ts_max_ = const_cast< ::cockroach::util::hlc::Timestamp*>(
      ::cockroach::util::hlc::Timestamp::internal_default_instance());
}

SSTUserProperties::SSTUserProperties(const SSTUserProperties& from)
  : ::google::protobuf::MessageLite(),
    _arena_ptr_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:cockroach.storage.engine.enginepb.SSTUserProperties)
}

void SSTUserProperties::SharedCtor() {
  path_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ts_min_ = NULL;
  ts_max_ = NULL;
  _cached_size_ = 0;
}

SSTUserProperties::~SSTUserProperties() {
  // @@protoc_insertion_point(destructor:cockroach.storage.engine.enginepb.SSTUserProperties)
  SharedDtor();
}

void SSTUserProperties::SharedDtor() {
  path_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != &SSTUserProperties_default_instance_.get()) {
    delete ts_min_;
    delete ts_max_;
  }
}

void SSTUserProperties::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const SSTUserProperties& SSTUserProperties::default_instance() {
  protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<SSTUserProperties> SSTUserProperties_default_instance_;

SSTUserProperties* SSTUserProperties::New(::google::protobuf::Arena* arena) const {
  SSTUserProperties* n = new SSTUserProperties;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SSTUserProperties::Clear() {
// @@protoc_insertion_point(message_clear_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  path_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && ts_min_ != NULL) delete ts_min_;
  ts_min_ = NULL;
  if (GetArenaNoVirtual() == NULL && ts_max_ != NULL) delete ts_max_;
  ts_max_ = NULL;
}

bool SSTUserProperties::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string path = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_path()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->path().data(), this->path().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cockroach.storage.engine.enginepb.SSTUserProperties.path"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_ts_min;
        break;
      }

      // optional .cockroach.util.hlc.Timestamp ts_min = 2;
      case 2: {
        if (tag == 18) {
         parse_ts_min:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_ts_min()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_ts_max;
        break;
      }

      // optional .cockroach.util.hlc.Timestamp ts_max = 3;
      case 3: {
        if (tag == 26) {
         parse_ts_max:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_ts_max()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:cockroach.storage.engine.enginepb.SSTUserProperties)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cockroach.storage.engine.enginepb.SSTUserProperties)
  return false;
#undef DO_
}

void SSTUserProperties::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  // optional string path = 1;
  if (this->path().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->path().data(), this->path().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cockroach.storage.engine.enginepb.SSTUserProperties.path");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->path(), output);
  }

  // optional .cockroach.util.hlc.Timestamp ts_min = 2;
  if (this->has_ts_min()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      2, *this->ts_min_, output);
  }

  // optional .cockroach.util.hlc.Timestamp ts_max = 3;
  if (this->has_ts_max()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, *this->ts_max_, output);
  }

  // @@protoc_insertion_point(serialize_end:cockroach.storage.engine.enginepb.SSTUserProperties)
}

size_t SSTUserProperties::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  size_t total_size = 0;

  // optional string path = 1;
  if (this->path().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->path());
  }

  // optional .cockroach.util.hlc.Timestamp ts_min = 2;
  if (this->has_ts_min()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->ts_min_);
  }

  // optional .cockroach.util.hlc.Timestamp ts_max = 3;
  if (this->has_ts_max()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->ts_max_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SSTUserProperties::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const SSTUserProperties*>(&from));
}

void SSTUserProperties::MergeFrom(const SSTUserProperties& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void SSTUserProperties::UnsafeMergeFrom(const SSTUserProperties& from) {
  GOOGLE_DCHECK(&from != this);
  if (from.path().size() > 0) {

    path_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
  if (from.has_ts_min()) {
    mutable_ts_min()->::cockroach::util::hlc::Timestamp::MergeFrom(from.ts_min());
  }
  if (from.has_ts_max()) {
    mutable_ts_max()->::cockroach::util::hlc::Timestamp::MergeFrom(from.ts_max());
  }
}

void SSTUserProperties::CopyFrom(const SSTUserProperties& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool SSTUserProperties::IsInitialized() const {

  return true;
}

void SSTUserProperties::Swap(SSTUserProperties* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SSTUserProperties::InternalSwap(SSTUserProperties* other) {
  path_.Swap(&other->path_);
  std::swap(ts_min_, other->ts_min_);
  std::swap(ts_max_, other->ts_max_);
  _unknown_fields_.Swap(&other->_unknown_fields_);
  std::swap(_cached_size_, other->_cached_size_);
}

::std::string SSTUserProperties::GetTypeName() const {
  return "cockroach.storage.engine.enginepb.SSTUserProperties";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SSTUserProperties

// optional string path = 1;
void SSTUserProperties::clear_path() {
  path_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& SSTUserProperties::path() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserProperties.path)
  return path_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void SSTUserProperties::set_path(const ::std::string& value) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}
void SSTUserProperties::set_path(const char* value) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}
void SSTUserProperties::set_path(const char* value, size_t size) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}
::std::string* SSTUserProperties::mutable_path() {
  
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserProperties.path)
  return path_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* SSTUserProperties::release_path() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserProperties.path)
  
  return path_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void SSTUserProperties::set_allocated_path(::std::string* path) {
  if (path != NULL) {
    
  } else {
    
  }
  path_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), path);
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}

// optional .cockroach.util.hlc.Timestamp ts_min = 2;
bool SSTUserProperties::has_ts_min() const {
  return this != internal_default_instance() && ts_min_ != NULL;
}
void SSTUserProperties::clear_ts_min() {
  if (GetArenaNoVirtual() == NULL && ts_min_ != NULL) delete ts_min_;
  ts_min_ = NULL;
}
const ::cockroach::util::hlc::Timestamp& SSTUserProperties::ts_min() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
  return ts_min_ != NULL ? *ts_min_
                         : *::cockroach::util::hlc::Timestamp::internal_default_instance();
}
::cockroach::util::hlc::Timestamp* SSTUserProperties::mutable_ts_min() {
  
  if (ts_min_ == NULL) {
    ts_min_ = new ::cockroach::util::hlc::Timestamp;
  }
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
  return ts_min_;
}
::cockroach::util::hlc::Timestamp* SSTUserProperties::release_ts_min() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
  
  ::cockroach::util::hlc::Timestamp* temp = ts_min_;
  ts_min_ = NULL;
  return temp;
}
void SSTUserProperties::set_allocated_ts_min(::cockroach::util::hlc::Timestamp* ts_min) {
  delete ts_min_;
  ts_min_ = ts_min;
  if (ts_min) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
}

// optional .cockroach.util.hlc.Timestamp ts_max = 3;
bool SSTUserProperties::has_ts_max() const {
  return this != internal_default_instance() && ts_max_ != NULL;
}
void SSTUserProperties::clear_ts_max() {
  if (GetArenaNoVirtual() == NULL && ts_max_ != NULL) delete ts_max_;
  ts_max_ = NULL;
}
const ::cockroach::util::hlc::Timestamp& SSTUserProperties::ts_max() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
  return ts_max_ != NULL ? *ts_max_
                         : *::cockroach::util::hlc::Timestamp::internal_default_instance();
}
::cockroach::util::hlc::Timestamp* SSTUserProperties::mutable_ts_max() {
  
  if (ts_max_ == NULL) {
    ts_max_ = new ::cockroach::util::hlc::Timestamp;
  }
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
  return ts_max_;
}
::cockroach::util::hlc::Timestamp* SSTUserProperties::release_ts_max() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
  
  ::cockroach::util::hlc::Timestamp* temp = ts_max_;
  ts_max_ = NULL;
  return temp;
}
void SSTUserProperties::set_allocated_ts_max(::cockroach::util::hlc::Timestamp* ts_max) {
  delete ts_max_;
  ts_max_ = ts_max;
  if (ts_max) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
}

inline const SSTUserProperties* SSTUserProperties::internal_default_instance() {
  return &SSTUserProperties_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SSTUserPropertiesCollection::kSstFieldNumber;
const int SSTUserPropertiesCollection::kErrorFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SSTUserPropertiesCollection::SSTUserPropertiesCollection()
  : ::google::protobuf::MessageLite(), _arena_ptr_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
}

void SSTUserPropertiesCollection::InitAsDefaultInstance() {
}

SSTUserPropertiesCollection::SSTUserPropertiesCollection(const SSTUserPropertiesCollection& from)
  : ::google::protobuf::MessageLite(),
    _arena_ptr_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
}

void SSTUserPropertiesCollection::SharedCtor() {
  error_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

SSTUserPropertiesCollection::~SSTUserPropertiesCollection() {
  // @@protoc_insertion_point(destructor:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  SharedDtor();
}

void SSTUserPropertiesCollection::SharedDtor() {
  error_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SSTUserPropertiesCollection::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const SSTUserPropertiesCollection& SSTUserPropertiesCollection::default_instance() {
  protobuf_InitDefaults_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<SSTUserPropertiesCollection> SSTUserPropertiesCollection_default_instance_;

SSTUserPropertiesCollection* SSTUserPropertiesCollection::New(::google::protobuf::Arena* arena) const {
  SSTUserPropertiesCollection* n = new SSTUserPropertiesCollection;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SSTUserPropertiesCollection::Clear() {
// @@protoc_insertion_point(message_clear_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  error_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sst_.Clear();
}

bool SSTUserPropertiesCollection::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .cockroach.storage.engine.enginepb.SSTUserProperties sst = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_sst:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_sst()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_sst;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectTag(18)) goto parse_error;
        break;
      }

      // optional string error = 2;
      case 2: {
        if (tag == 18) {
         parse_error:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->error().data(), this->error().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  return false;
#undef DO_
}

void SSTUserPropertiesCollection::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  // repeated .cockroach.storage.engine.enginepb.SSTUserProperties sst = 1;
  for (unsigned int i = 0, n = this->sst_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->sst(i), output);
  }

  // optional string error = 2;
  if (this->error().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->error().data(), this->error().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->error(), output);
  }

  // @@protoc_insertion_point(serialize_end:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
}

size_t SSTUserPropertiesCollection::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  size_t total_size = 0;

  // optional string error = 2;
  if (this->error().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->error());
  }

  // repeated .cockroach.storage.engine.enginepb.SSTUserProperties sst = 1;
  {
    unsigned int count = this->sst_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->sst(i));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SSTUserPropertiesCollection::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const SSTUserPropertiesCollection*>(&from));
}

void SSTUserPropertiesCollection::MergeFrom(const SSTUserPropertiesCollection& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void SSTUserPropertiesCollection::UnsafeMergeFrom(const SSTUserPropertiesCollection& from) {
  GOOGLE_DCHECK(&from != this);
  sst_.MergeFrom(from.sst_);
  if (from.error().size() > 0) {

    error_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_);
  }
}

void SSTUserPropertiesCollection::CopyFrom(const SSTUserPropertiesCollection& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool SSTUserPropertiesCollection::IsInitialized() const {

  return true;
}

void SSTUserPropertiesCollection::Swap(SSTUserPropertiesCollection* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SSTUserPropertiesCollection::InternalSwap(SSTUserPropertiesCollection* other) {
  sst_.UnsafeArenaSwap(&other->sst_);
  error_.Swap(&other->error_);
  _unknown_fields_.Swap(&other->_unknown_fields_);
  std::swap(_cached_size_, other->_cached_size_);
}

::std::string SSTUserPropertiesCollection::GetTypeName() const {
  return "cockroach.storage.engine.enginepb.SSTUserPropertiesCollection";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SSTUserPropertiesCollection

// repeated .cockroach.storage.engine.enginepb.SSTUserProperties sst = 1;
int SSTUserPropertiesCollection::sst_size() const {
  return sst_.size();
}
void SSTUserPropertiesCollection::clear_sst() {
  sst_.Clear();
}
const ::cockroach::storage::engine::enginepb::SSTUserProperties& SSTUserPropertiesCollection::sst(int index) const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_.Get(index);
}
::cockroach::storage::engine::enginepb::SSTUserProperties* SSTUserPropertiesCollection::mutable_sst(int index) {
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_.Mutable(index);
}
::cockroach::storage::engine::enginepb::SSTUserProperties* SSTUserPropertiesCollection::add_sst() {
  // @@protoc_insertion_point(field_add:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_.Add();
}
::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::SSTUserProperties >*
SSTUserPropertiesCollection::mutable_sst() {
  // @@protoc_insertion_point(field_mutable_list:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return &sst_;
}
const ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::SSTUserProperties >&
SSTUserPropertiesCollection::sst() const {
  // @@protoc_insertion_point(field_list:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_;
}

// optional string error = 2;
void SSTUserPropertiesCollection::clear_error() {
  error_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& SSTUserPropertiesCollection::error() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
  return error_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void SSTUserPropertiesCollection::set_error(const ::std::string& value) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}
void SSTUserPropertiesCollection::set_error(const char* value) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}
void SSTUserPropertiesCollection::set_error(const char* value, size_t size) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}
::std::string* SSTUserPropertiesCollection::mutable_error() {
  
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
  return error_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* SSTUserPropertiesCollection::release_error() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
  
  return error_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void SSTUserPropertiesCollection::set_allocated_error(::std::string* error) {
  if (error != NULL) {
    
  } else {
    
  }
  error_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), error);
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}

inline const SSTUserPropertiesCollection* SSTUserPropertiesCollection::internal_default_instance() {
  return &SSTUserPropertiesCollection_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach

// @@protoc_insertion_point(global_scope)
