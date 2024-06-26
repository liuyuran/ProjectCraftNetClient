// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/client.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2fclient_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_proto_2fclient_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_proto_2fclient_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2fclient_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_proto_2fclient_2eproto;
class PlayerControlBlock;
struct PlayerControlBlockDefaultTypeInternal;
extern PlayerControlBlockDefaultTypeInternal _PlayerControlBlock_default_instance_;
class PlayerControlEntity;
struct PlayerControlEntityDefaultTypeInternal;
extern PlayerControlEntityDefaultTypeInternal _PlayerControlEntity_default_instance_;
class PlayerMove;
struct PlayerMoveDefaultTypeInternal;
extern PlayerMoveDefaultTypeInternal _PlayerMove_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class PlayerMove final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PlayerMove) */ {
 public:
  inline PlayerMove() : PlayerMove(nullptr) {}
  ~PlayerMove() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR PlayerMove(::google::protobuf::internal::ConstantInitialized);

  inline PlayerMove(const PlayerMove& from)
      : PlayerMove(nullptr, from) {}
  PlayerMove(PlayerMove&& from) noexcept
    : PlayerMove() {
    *this = ::std::move(from);
  }

  inline PlayerMove& operator=(const PlayerMove& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerMove& operator=(PlayerMove&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerMove& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerMove* internal_default_instance() {
    return reinterpret_cast<const PlayerMove*>(
               &_PlayerMove_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PlayerMove& a, PlayerMove& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerMove* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerMove* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PlayerMove* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PlayerMove>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const PlayerMove& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const PlayerMove& from) {
    PlayerMove::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(PlayerMove* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "PlayerMove";
  }
  protected:
  explicit PlayerMove(::google::protobuf::Arena* arena);
  PlayerMove(::google::protobuf::Arena* arena, const PlayerMove& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kChunkXFieldNumber = 1,
    kChunkYFieldNumber = 2,
    kChunkZFieldNumber = 3,
    kXFieldNumber = 4,
    kYFieldNumber = 5,
    kZFieldNumber = 6,
    kYawFieldNumber = 7,
    kPitchFieldNumber = 8,
    kHeadYawFieldNumber = 9,
    kPlayerIdFieldNumber = 10,
  };
  // int32 chunk_x = 1;
  void clear_chunk_x() ;
  ::int32_t chunk_x() const;
  void set_chunk_x(::int32_t value);

  private:
  ::int32_t _internal_chunk_x() const;
  void _internal_set_chunk_x(::int32_t value);

  public:
  // int32 chunk_y = 2;
  void clear_chunk_y() ;
  ::int32_t chunk_y() const;
  void set_chunk_y(::int32_t value);

  private:
  ::int32_t _internal_chunk_y() const;
  void _internal_set_chunk_y(::int32_t value);

  public:
  // int32 chunk_z = 3;
  void clear_chunk_z() ;
  ::int32_t chunk_z() const;
  void set_chunk_z(::int32_t value);

  private:
  ::int32_t _internal_chunk_z() const;
  void _internal_set_chunk_z(::int32_t value);

  public:
  // float x = 4;
  void clear_x() ;
  float x() const;
  void set_x(float value);

  private:
  float _internal_x() const;
  void _internal_set_x(float value);

  public:
  // float y = 5;
  void clear_y() ;
  float y() const;
  void set_y(float value);

  private:
  float _internal_y() const;
  void _internal_set_y(float value);

  public:
  // float z = 6;
  void clear_z() ;
  float z() const;
  void set_z(float value);

  private:
  float _internal_z() const;
  void _internal_set_z(float value);

  public:
  // float yaw = 7;
  void clear_yaw() ;
  float yaw() const;
  void set_yaw(float value);

  private:
  float _internal_yaw() const;
  void _internal_set_yaw(float value);

  public:
  // float pitch = 8;
  void clear_pitch() ;
  float pitch() const;
  void set_pitch(float value);

  private:
  float _internal_pitch() const;
  void _internal_set_pitch(float value);

  public:
  // float head_yaw = 9;
  void clear_head_yaw() ;
  float head_yaw() const;
  void set_head_yaw(float value);

  private:
  float _internal_head_yaw() const;
  void _internal_set_head_yaw(float value);

  public:
  // uint32 player_id = 10;
  void clear_player_id() ;
  ::uint32_t player_id() const;
  void set_player_id(::uint32_t value);

  private:
  ::uint32_t _internal_player_id() const;
  void _internal_set_player_id(::uint32_t value);

  public:
  // @@protoc_insertion_point(class_scope:PlayerMove)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      4, 10, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::int32_t chunk_x_;
    ::int32_t chunk_y_;
    ::int32_t chunk_z_;
    float x_;
    float y_;
    float z_;
    float yaw_;
    float pitch_;
    float head_yaw_;
    ::uint32_t player_id_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_proto_2fclient_2eproto;
};// -------------------------------------------------------------------

class PlayerControlEntity final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PlayerControlEntity) */ {
 public:
  inline PlayerControlEntity() : PlayerControlEntity(nullptr) {}
  ~PlayerControlEntity() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR PlayerControlEntity(::google::protobuf::internal::ConstantInitialized);

  inline PlayerControlEntity(const PlayerControlEntity& from)
      : PlayerControlEntity(nullptr, from) {}
  PlayerControlEntity(PlayerControlEntity&& from) noexcept
    : PlayerControlEntity() {
    *this = ::std::move(from);
  }

  inline PlayerControlEntity& operator=(const PlayerControlEntity& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerControlEntity& operator=(PlayerControlEntity&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerControlEntity& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerControlEntity* internal_default_instance() {
    return reinterpret_cast<const PlayerControlEntity*>(
               &_PlayerControlEntity_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(PlayerControlEntity& a, PlayerControlEntity& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerControlEntity* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerControlEntity* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PlayerControlEntity* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PlayerControlEntity>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const PlayerControlEntity& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const PlayerControlEntity& from) {
    PlayerControlEntity::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(PlayerControlEntity* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "PlayerControlEntity";
  }
  protected:
  explicit PlayerControlEntity(::google::protobuf::Arena* arena);
  PlayerControlEntity(::google::protobuf::Arena* arena, const PlayerControlEntity& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTargetIdFieldNumber = 2,
    kTypeFieldNumber = 1,
  };
  // int64 target_id = 2;
  void clear_target_id() ;
  ::int64_t target_id() const;
  void set_target_id(::int64_t value);

  private:
  ::int64_t _internal_target_id() const;
  void _internal_set_target_id(::int64_t value);

  public:
  // int32 type = 1;
  void clear_type() ;
  ::int32_t type() const;
  void set_type(::int32_t value);

  private:
  ::int32_t _internal_type() const;
  void _internal_set_type(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:PlayerControlEntity)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::int64_t target_id_;
    ::int32_t type_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_proto_2fclient_2eproto;
};// -------------------------------------------------------------------

class PlayerControlBlock final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PlayerControlBlock) */ {
 public:
  inline PlayerControlBlock() : PlayerControlBlock(nullptr) {}
  ~PlayerControlBlock() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR PlayerControlBlock(::google::protobuf::internal::ConstantInitialized);

  inline PlayerControlBlock(const PlayerControlBlock& from)
      : PlayerControlBlock(nullptr, from) {}
  PlayerControlBlock(PlayerControlBlock&& from) noexcept
    : PlayerControlBlock() {
    *this = ::std::move(from);
  }

  inline PlayerControlBlock& operator=(const PlayerControlBlock& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerControlBlock& operator=(PlayerControlBlock&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerControlBlock& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerControlBlock* internal_default_instance() {
    return reinterpret_cast<const PlayerControlBlock*>(
               &_PlayerControlBlock_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PlayerControlBlock& a, PlayerControlBlock& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerControlBlock* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerControlBlock* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PlayerControlBlock* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PlayerControlBlock>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const PlayerControlBlock& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const PlayerControlBlock& from) {
    PlayerControlBlock::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(PlayerControlBlock* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "PlayerControlBlock";
  }
  protected:
  explicit PlayerControlBlock(::google::protobuf::Arena* arena);
  PlayerControlBlock(::google::protobuf::Arena* arena, const PlayerControlBlock& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTypeFieldNumber = 1,
    kChunkXFieldNumber = 2,
    kChunkYFieldNumber = 3,
    kChunkZFieldNumber = 4,
    kBlockXFieldNumber = 5,
    kBlockYFieldNumber = 6,
    kBlockZFieldNumber = 7,
  };
  // int32 type = 1;
  void clear_type() ;
  ::int32_t type() const;
  void set_type(::int32_t value);

  private:
  ::int32_t _internal_type() const;
  void _internal_set_type(::int32_t value);

  public:
  // int32 chunk_x = 2;
  void clear_chunk_x() ;
  ::int32_t chunk_x() const;
  void set_chunk_x(::int32_t value);

  private:
  ::int32_t _internal_chunk_x() const;
  void _internal_set_chunk_x(::int32_t value);

  public:
  // int32 chunk_y = 3;
  void clear_chunk_y() ;
  ::int32_t chunk_y() const;
  void set_chunk_y(::int32_t value);

  private:
  ::int32_t _internal_chunk_y() const;
  void _internal_set_chunk_y(::int32_t value);

  public:
  // int32 chunk_z = 4;
  void clear_chunk_z() ;
  ::int32_t chunk_z() const;
  void set_chunk_z(::int32_t value);

  private:
  ::int32_t _internal_chunk_z() const;
  void _internal_set_chunk_z(::int32_t value);

  public:
  // int32 block_x = 5;
  void clear_block_x() ;
  ::int32_t block_x() const;
  void set_block_x(::int32_t value);

  private:
  ::int32_t _internal_block_x() const;
  void _internal_set_block_x(::int32_t value);

  public:
  // int32 block_y = 6;
  void clear_block_y() ;
  ::int32_t block_y() const;
  void set_block_y(::int32_t value);

  private:
  ::int32_t _internal_block_y() const;
  void _internal_set_block_y(::int32_t value);

  public:
  // int32 block_z = 7;
  void clear_block_z() ;
  ::int32_t block_z() const;
  void set_block_z(::int32_t value);

  private:
  ::int32_t _internal_block_z() const;
  void _internal_set_block_z(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:PlayerControlBlock)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 7, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::int32_t type_;
    ::int32_t chunk_x_;
    ::int32_t chunk_y_;
    ::int32_t chunk_z_;
    ::int32_t block_x_;
    ::int32_t block_y_;
    ::int32_t block_z_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_proto_2fclient_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// PlayerMove

// int32 chunk_x = 1;
inline void PlayerMove::clear_chunk_x() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.chunk_x_ = 0;
}
inline ::int32_t PlayerMove::chunk_x() const {
  // @@protoc_insertion_point(field_get:PlayerMove.chunk_x)
  return _internal_chunk_x();
}
inline void PlayerMove::set_chunk_x(::int32_t value) {
  _internal_set_chunk_x(value);
  // @@protoc_insertion_point(field_set:PlayerMove.chunk_x)
}
inline ::int32_t PlayerMove::_internal_chunk_x() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.chunk_x_;
}
inline void PlayerMove::_internal_set_chunk_x(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.chunk_x_ = value;
}

// int32 chunk_y = 2;
inline void PlayerMove::clear_chunk_y() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.chunk_y_ = 0;
}
inline ::int32_t PlayerMove::chunk_y() const {
  // @@protoc_insertion_point(field_get:PlayerMove.chunk_y)
  return _internal_chunk_y();
}
inline void PlayerMove::set_chunk_y(::int32_t value) {
  _internal_set_chunk_y(value);
  // @@protoc_insertion_point(field_set:PlayerMove.chunk_y)
}
inline ::int32_t PlayerMove::_internal_chunk_y() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.chunk_y_;
}
inline void PlayerMove::_internal_set_chunk_y(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.chunk_y_ = value;
}

// int32 chunk_z = 3;
inline void PlayerMove::clear_chunk_z() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.chunk_z_ = 0;
}
inline ::int32_t PlayerMove::chunk_z() const {
  // @@protoc_insertion_point(field_get:PlayerMove.chunk_z)
  return _internal_chunk_z();
}
inline void PlayerMove::set_chunk_z(::int32_t value) {
  _internal_set_chunk_z(value);
  // @@protoc_insertion_point(field_set:PlayerMove.chunk_z)
}
inline ::int32_t PlayerMove::_internal_chunk_z() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.chunk_z_;
}
inline void PlayerMove::_internal_set_chunk_z(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.chunk_z_ = value;
}

// float x = 4;
inline void PlayerMove::clear_x() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.x_ = 0;
}
inline float PlayerMove::x() const {
  // @@protoc_insertion_point(field_get:PlayerMove.x)
  return _internal_x();
}
inline void PlayerMove::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:PlayerMove.x)
}
inline float PlayerMove::_internal_x() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.x_;
}
inline void PlayerMove::_internal_set_x(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.x_ = value;
}

// float y = 5;
inline void PlayerMove::clear_y() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.y_ = 0;
}
inline float PlayerMove::y() const {
  // @@protoc_insertion_point(field_get:PlayerMove.y)
  return _internal_y();
}
inline void PlayerMove::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:PlayerMove.y)
}
inline float PlayerMove::_internal_y() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.y_;
}
inline void PlayerMove::_internal_set_y(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.y_ = value;
}

// float z = 6;
inline void PlayerMove::clear_z() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.z_ = 0;
}
inline float PlayerMove::z() const {
  // @@protoc_insertion_point(field_get:PlayerMove.z)
  return _internal_z();
}
inline void PlayerMove::set_z(float value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:PlayerMove.z)
}
inline float PlayerMove::_internal_z() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.z_;
}
inline void PlayerMove::_internal_set_z(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.z_ = value;
}

// float yaw = 7;
inline void PlayerMove::clear_yaw() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.yaw_ = 0;
}
inline float PlayerMove::yaw() const {
  // @@protoc_insertion_point(field_get:PlayerMove.yaw)
  return _internal_yaw();
}
inline void PlayerMove::set_yaw(float value) {
  _internal_set_yaw(value);
  // @@protoc_insertion_point(field_set:PlayerMove.yaw)
}
inline float PlayerMove::_internal_yaw() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.yaw_;
}
inline void PlayerMove::_internal_set_yaw(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.yaw_ = value;
}

// float pitch = 8;
inline void PlayerMove::clear_pitch() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.pitch_ = 0;
}
inline float PlayerMove::pitch() const {
  // @@protoc_insertion_point(field_get:PlayerMove.pitch)
  return _internal_pitch();
}
inline void PlayerMove::set_pitch(float value) {
  _internal_set_pitch(value);
  // @@protoc_insertion_point(field_set:PlayerMove.pitch)
}
inline float PlayerMove::_internal_pitch() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.pitch_;
}
inline void PlayerMove::_internal_set_pitch(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.pitch_ = value;
}

// float head_yaw = 9;
inline void PlayerMove::clear_head_yaw() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.head_yaw_ = 0;
}
inline float PlayerMove::head_yaw() const {
  // @@protoc_insertion_point(field_get:PlayerMove.head_yaw)
  return _internal_head_yaw();
}
inline void PlayerMove::set_head_yaw(float value) {
  _internal_set_head_yaw(value);
  // @@protoc_insertion_point(field_set:PlayerMove.head_yaw)
}
inline float PlayerMove::_internal_head_yaw() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.head_yaw_;
}
inline void PlayerMove::_internal_set_head_yaw(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.head_yaw_ = value;
}

// uint32 player_id = 10;
inline void PlayerMove::clear_player_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.player_id_ = 0u;
}
inline ::uint32_t PlayerMove::player_id() const {
  // @@protoc_insertion_point(field_get:PlayerMove.player_id)
  return _internal_player_id();
}
inline void PlayerMove::set_player_id(::uint32_t value) {
  _internal_set_player_id(value);
  // @@protoc_insertion_point(field_set:PlayerMove.player_id)
}
inline ::uint32_t PlayerMove::_internal_player_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.player_id_;
}
inline void PlayerMove::_internal_set_player_id(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.player_id_ = value;
}

// -------------------------------------------------------------------

// PlayerControlBlock

// int32 type = 1;
inline void PlayerControlBlock::clear_type() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.type_ = 0;
}
inline ::int32_t PlayerControlBlock::type() const {
  // @@protoc_insertion_point(field_get:PlayerControlBlock.type)
  return _internal_type();
}
inline void PlayerControlBlock::set_type(::int32_t value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:PlayerControlBlock.type)
}
inline ::int32_t PlayerControlBlock::_internal_type() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.type_;
}
inline void PlayerControlBlock::_internal_set_type(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.type_ = value;
}

// int32 chunk_x = 2;
inline void PlayerControlBlock::clear_chunk_x() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.chunk_x_ = 0;
}
inline ::int32_t PlayerControlBlock::chunk_x() const {
  // @@protoc_insertion_point(field_get:PlayerControlBlock.chunk_x)
  return _internal_chunk_x();
}
inline void PlayerControlBlock::set_chunk_x(::int32_t value) {
  _internal_set_chunk_x(value);
  // @@protoc_insertion_point(field_set:PlayerControlBlock.chunk_x)
}
inline ::int32_t PlayerControlBlock::_internal_chunk_x() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.chunk_x_;
}
inline void PlayerControlBlock::_internal_set_chunk_x(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.chunk_x_ = value;
}

// int32 chunk_y = 3;
inline void PlayerControlBlock::clear_chunk_y() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.chunk_y_ = 0;
}
inline ::int32_t PlayerControlBlock::chunk_y() const {
  // @@protoc_insertion_point(field_get:PlayerControlBlock.chunk_y)
  return _internal_chunk_y();
}
inline void PlayerControlBlock::set_chunk_y(::int32_t value) {
  _internal_set_chunk_y(value);
  // @@protoc_insertion_point(field_set:PlayerControlBlock.chunk_y)
}
inline ::int32_t PlayerControlBlock::_internal_chunk_y() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.chunk_y_;
}
inline void PlayerControlBlock::_internal_set_chunk_y(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.chunk_y_ = value;
}

// int32 chunk_z = 4;
inline void PlayerControlBlock::clear_chunk_z() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.chunk_z_ = 0;
}
inline ::int32_t PlayerControlBlock::chunk_z() const {
  // @@protoc_insertion_point(field_get:PlayerControlBlock.chunk_z)
  return _internal_chunk_z();
}
inline void PlayerControlBlock::set_chunk_z(::int32_t value) {
  _internal_set_chunk_z(value);
  // @@protoc_insertion_point(field_set:PlayerControlBlock.chunk_z)
}
inline ::int32_t PlayerControlBlock::_internal_chunk_z() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.chunk_z_;
}
inline void PlayerControlBlock::_internal_set_chunk_z(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.chunk_z_ = value;
}

// int32 block_x = 5;
inline void PlayerControlBlock::clear_block_x() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.block_x_ = 0;
}
inline ::int32_t PlayerControlBlock::block_x() const {
  // @@protoc_insertion_point(field_get:PlayerControlBlock.block_x)
  return _internal_block_x();
}
inline void PlayerControlBlock::set_block_x(::int32_t value) {
  _internal_set_block_x(value);
  // @@protoc_insertion_point(field_set:PlayerControlBlock.block_x)
}
inline ::int32_t PlayerControlBlock::_internal_block_x() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.block_x_;
}
inline void PlayerControlBlock::_internal_set_block_x(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.block_x_ = value;
}

// int32 block_y = 6;
inline void PlayerControlBlock::clear_block_y() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.block_y_ = 0;
}
inline ::int32_t PlayerControlBlock::block_y() const {
  // @@protoc_insertion_point(field_get:PlayerControlBlock.block_y)
  return _internal_block_y();
}
inline void PlayerControlBlock::set_block_y(::int32_t value) {
  _internal_set_block_y(value);
  // @@protoc_insertion_point(field_set:PlayerControlBlock.block_y)
}
inline ::int32_t PlayerControlBlock::_internal_block_y() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.block_y_;
}
inline void PlayerControlBlock::_internal_set_block_y(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.block_y_ = value;
}

// int32 block_z = 7;
inline void PlayerControlBlock::clear_block_z() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.block_z_ = 0;
}
inline ::int32_t PlayerControlBlock::block_z() const {
  // @@protoc_insertion_point(field_get:PlayerControlBlock.block_z)
  return _internal_block_z();
}
inline void PlayerControlBlock::set_block_z(::int32_t value) {
  _internal_set_block_z(value);
  // @@protoc_insertion_point(field_set:PlayerControlBlock.block_z)
}
inline ::int32_t PlayerControlBlock::_internal_block_z() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.block_z_;
}
inline void PlayerControlBlock::_internal_set_block_z(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.block_z_ = value;
}

// -------------------------------------------------------------------

// PlayerControlEntity

// int32 type = 1;
inline void PlayerControlEntity::clear_type() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.type_ = 0;
}
inline ::int32_t PlayerControlEntity::type() const {
  // @@protoc_insertion_point(field_get:PlayerControlEntity.type)
  return _internal_type();
}
inline void PlayerControlEntity::set_type(::int32_t value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:PlayerControlEntity.type)
}
inline ::int32_t PlayerControlEntity::_internal_type() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.type_;
}
inline void PlayerControlEntity::_internal_set_type(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.type_ = value;
}

// int64 target_id = 2;
inline void PlayerControlEntity::clear_target_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.target_id_ = ::int64_t{0};
}
inline ::int64_t PlayerControlEntity::target_id() const {
  // @@protoc_insertion_point(field_get:PlayerControlEntity.target_id)
  return _internal_target_id();
}
inline void PlayerControlEntity::set_target_id(::int64_t value) {
  _internal_set_target_id(value);
  // @@protoc_insertion_point(field_set:PlayerControlEntity.target_id)
}
inline ::int64_t PlayerControlEntity::_internal_target_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.target_id_;
}
inline void PlayerControlEntity::_internal_set_target_id(::int64_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.target_id_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_proto_2fclient_2eproto_2epb_2eh
