// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: camera_image.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "camera_image.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace SensorNearData {
namespace MFC {

namespace {

const ::google::protobuf::Descriptor* CameraImage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CameraImage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_camera_5fimage_2eproto() {
  protobuf_AddDesc_camera_5fimage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "camera_image.proto");
  GOOGLE_CHECK(file != NULL);
  CameraImage_descriptor_ = file->message_type(0);
  static const int CameraImage_offsets_[18] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, header_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_counter_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_height_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_shift_u_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_shift_v_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, o_image_width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, o_image_height_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, imager_size_u_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, imager_size_v_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, o_image_pattern_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_compressed_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_compression_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, byte_per_pixel_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, bit_per_pixel_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, image_payload_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, bmp_image_),
  };
  CameraImage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CameraImage_descriptor_,
      CameraImage::default_instance_,
      CameraImage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CameraImage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CameraImage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_camera_5fimage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CameraImage_descriptor_, &CameraImage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_camera_5fimage_2eproto() {
  delete CameraImage::default_instance_;
  delete CameraImage_reflection_;
}

void protobuf_AddDesc_camera_5fimage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_header_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022camera_image.proto\022\022SensorNearData.MFC"
    "\032\014header.proto\"\362\003\n\013CameraImage\022\027\n\006header"
    "\030\001 \001(\0132\007.Header\022\030\n\rimage_counter\030\002 \001(\r:\001"
    "0\022\031\n\013image_width\030\003 \001(\021:\0041176\022\031\n\014image_he"
    "ight\030\004 \001(\021:\003640\022\030\n\rimage_shift_u\030\005 \001(\021:\001"
    "0\022\030\n\rimage_shift_v\030\006 \001(\021:\0010\022\033\n\ro_image_w"
    "idth\030\007 \001(\021:\0041176\022\033\n\016o_image_height\030\010 \001(\021"
    ":\003640\022\033\n\rimager_size_u\030\t \001(\021:\0041280\022\032\n\rim"
    "ager_size_v\030\n \001(\021:\003960\022\032\n\017o_image_patter"
    "n\030\013 \001(\r:\0013\022\036\n\020image_compressed\030\014 \001(\010:\004tr"
    "ue\022!\n\026image_compression_type\030\r \001(\r:\0012\022\025\n"
    "\nimage_type\030\016 \001(\r:\0013\022\031\n\016byte_per_pixel\030\017"
    " \001(\r:\0011\022\030\n\rbit_per_pixel\030\020 \001(\r:\0018\022\025\n\rima"
    "ge_payload\030\021 \001(\014\022\021\n\tbmp_image\030\022 \001(\014", 555);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "camera_image.proto", &protobuf_RegisterTypes);
  CameraImage::default_instance_ = new CameraImage();
  CameraImage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_camera_5fimage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_camera_5fimage_2eproto {
  StaticDescriptorInitializer_camera_5fimage_2eproto() {
    protobuf_AddDesc_camera_5fimage_2eproto();
  }
} static_descriptor_initializer_camera_5fimage_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int CameraImage::kHeaderFieldNumber;
const int CameraImage::kImageCounterFieldNumber;
const int CameraImage::kImageWidthFieldNumber;
const int CameraImage::kImageHeightFieldNumber;
const int CameraImage::kImageShiftUFieldNumber;
const int CameraImage::kImageShiftVFieldNumber;
const int CameraImage::kOImageWidthFieldNumber;
const int CameraImage::kOImageHeightFieldNumber;
const int CameraImage::kImagerSizeUFieldNumber;
const int CameraImage::kImagerSizeVFieldNumber;
const int CameraImage::kOImagePatternFieldNumber;
const int CameraImage::kImageCompressedFieldNumber;
const int CameraImage::kImageCompressionTypeFieldNumber;
const int CameraImage::kImageTypeFieldNumber;
const int CameraImage::kBytePerPixelFieldNumber;
const int CameraImage::kBitPerPixelFieldNumber;
const int CameraImage::kImagePayloadFieldNumber;
const int CameraImage::kBmpImageFieldNumber;
#endif  // !_MSC_VER

CameraImage::CameraImage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SensorNearData.MFC.CameraImage)
}

void CameraImage::InitAsDefaultInstance() {
  header_ = const_cast< ::Header*>(&::Header::default_instance());
}

CameraImage::CameraImage(const CameraImage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SensorNearData.MFC.CameraImage)
}

void CameraImage::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  header_ = NULL;
  image_counter_ = 0u;
  image_width_ = 1176;
  image_height_ = 640;
  image_shift_u_ = 0;
  image_shift_v_ = 0;
  o_image_width_ = 1176;
  o_image_height_ = 640;
  imager_size_u_ = 1280;
  imager_size_v_ = 960;
  o_image_pattern_ = 3u;
  image_compressed_ = true;
  image_compression_type_ = 2u;
  image_type_ = 3u;
  byte_per_pixel_ = 1u;
  bit_per_pixel_ = 8u;
  image_payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  bmp_image_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CameraImage::~CameraImage() {
  // @@protoc_insertion_point(destructor:SensorNearData.MFC.CameraImage)
  SharedDtor();
}

void CameraImage::SharedDtor() {
  if (image_payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete image_payload_;
  }
  if (bmp_image_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete bmp_image_;
  }
  if (this != default_instance_) {
    delete header_;
  }
}

void CameraImage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CameraImage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CameraImage_descriptor_;
}

const CameraImage& CameraImage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_camera_5fimage_2eproto();
  return *default_instance_;
}

CameraImage* CameraImage::default_instance_ = NULL;

CameraImage* CameraImage::New() const {
  return new CameraImage;
}

void CameraImage::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<CameraImage*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(image_shift_u_, image_shift_v_);
    if (has_header()) {
      if (header_ != NULL) header_->::Header::Clear();
    }
    image_counter_ = 0u;
    image_width_ = 1176;
    image_height_ = 640;
    o_image_width_ = 1176;
    o_image_height_ = 640;
  }
  if (_has_bits_[8 / 32] & 65280) {
    imager_size_u_ = 1280;
    imager_size_v_ = 960;
    o_image_pattern_ = 3u;
    image_compressed_ = true;
    image_compression_type_ = 2u;
    image_type_ = 3u;
    byte_per_pixel_ = 1u;
    bit_per_pixel_ = 8u;
  }
  if (_has_bits_[16 / 32] & 196608) {
    if (has_image_payload()) {
      if (image_payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        image_payload_->clear();
      }
    }
    if (has_bmp_image()) {
      if (bmp_image_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        bmp_image_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CameraImage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SensorNearData.MFC.CameraImage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .Header header = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_header()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_image_counter;
        break;
      }

      // optional uint32 image_counter = 2 [default = 0];
      case 2: {
        if (tag == 16) {
         parse_image_counter:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &image_counter_)));
          set_has_image_counter();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_image_width;
        break;
      }

      // optional sint32 image_width = 3 [default = 1176];
      case 3: {
        if (tag == 24) {
         parse_image_width:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &image_width_)));
          set_has_image_width();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_image_height;
        break;
      }

      // optional sint32 image_height = 4 [default = 640];
      case 4: {
        if (tag == 32) {
         parse_image_height:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &image_height_)));
          set_has_image_height();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_image_shift_u;
        break;
      }

      // optional sint32 image_shift_u = 5 [default = 0];
      case 5: {
        if (tag == 40) {
         parse_image_shift_u:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &image_shift_u_)));
          set_has_image_shift_u();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_image_shift_v;
        break;
      }

      // optional sint32 image_shift_v = 6 [default = 0];
      case 6: {
        if (tag == 48) {
         parse_image_shift_v:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &image_shift_v_)));
          set_has_image_shift_v();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_o_image_width;
        break;
      }

      // optional sint32 o_image_width = 7 [default = 1176];
      case 7: {
        if (tag == 56) {
         parse_o_image_width:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &o_image_width_)));
          set_has_o_image_width();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_o_image_height;
        break;
      }

      // optional sint32 o_image_height = 8 [default = 640];
      case 8: {
        if (tag == 64) {
         parse_o_image_height:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &o_image_height_)));
          set_has_o_image_height();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_imager_size_u;
        break;
      }

      // optional sint32 imager_size_u = 9 [default = 1280];
      case 9: {
        if (tag == 72) {
         parse_imager_size_u:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &imager_size_u_)));
          set_has_imager_size_u();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_imager_size_v;
        break;
      }

      // optional sint32 imager_size_v = 10 [default = 960];
      case 10: {
        if (tag == 80) {
         parse_imager_size_v:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &imager_size_v_)));
          set_has_imager_size_v();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(88)) goto parse_o_image_pattern;
        break;
      }

      // optional uint32 o_image_pattern = 11 [default = 3];
      case 11: {
        if (tag == 88) {
         parse_o_image_pattern:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &o_image_pattern_)));
          set_has_o_image_pattern();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(96)) goto parse_image_compressed;
        break;
      }

      // optional bool image_compressed = 12 [default = true];
      case 12: {
        if (tag == 96) {
         parse_image_compressed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &image_compressed_)));
          set_has_image_compressed();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(104)) goto parse_image_compression_type;
        break;
      }

      // optional uint32 image_compression_type = 13 [default = 2];
      case 13: {
        if (tag == 104) {
         parse_image_compression_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &image_compression_type_)));
          set_has_image_compression_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(112)) goto parse_image_type;
        break;
      }

      // optional uint32 image_type = 14 [default = 3];
      case 14: {
        if (tag == 112) {
         parse_image_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &image_type_)));
          set_has_image_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(120)) goto parse_byte_per_pixel;
        break;
      }

      // optional uint32 byte_per_pixel = 15 [default = 1];
      case 15: {
        if (tag == 120) {
         parse_byte_per_pixel:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &byte_per_pixel_)));
          set_has_byte_per_pixel();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(128)) goto parse_bit_per_pixel;
        break;
      }

      // optional uint32 bit_per_pixel = 16 [default = 8];
      case 16: {
        if (tag == 128) {
         parse_bit_per_pixel:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &bit_per_pixel_)));
          set_has_bit_per_pixel();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(138)) goto parse_image_payload;
        break;
      }

      // optional bytes image_payload = 17;
      case 17: {
        if (tag == 138) {
         parse_image_payload:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_image_payload()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(146)) goto parse_bmp_image;
        break;
      }

      // optional bytes bmp_image = 18;
      case 18: {
        if (tag == 146) {
         parse_bmp_image:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_bmp_image()));
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
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SensorNearData.MFC.CameraImage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SensorNearData.MFC.CameraImage)
  return false;
#undef DO_
}

void CameraImage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SensorNearData.MFC.CameraImage)
  // optional .Header header = 1;
  if (has_header()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->header(), output);
  }

  // optional uint32 image_counter = 2 [default = 0];
  if (has_image_counter()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->image_counter(), output);
  }

  // optional sint32 image_width = 3 [default = 1176];
  if (has_image_width()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(3, this->image_width(), output);
  }

  // optional sint32 image_height = 4 [default = 640];
  if (has_image_height()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(4, this->image_height(), output);
  }

  // optional sint32 image_shift_u = 5 [default = 0];
  if (has_image_shift_u()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(5, this->image_shift_u(), output);
  }

  // optional sint32 image_shift_v = 6 [default = 0];
  if (has_image_shift_v()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(6, this->image_shift_v(), output);
  }

  // optional sint32 o_image_width = 7 [default = 1176];
  if (has_o_image_width()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(7, this->o_image_width(), output);
  }

  // optional sint32 o_image_height = 8 [default = 640];
  if (has_o_image_height()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(8, this->o_image_height(), output);
  }

  // optional sint32 imager_size_u = 9 [default = 1280];
  if (has_imager_size_u()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(9, this->imager_size_u(), output);
  }

  // optional sint32 imager_size_v = 10 [default = 960];
  if (has_imager_size_v()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(10, this->imager_size_v(), output);
  }

  // optional uint32 o_image_pattern = 11 [default = 3];
  if (has_o_image_pattern()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(11, this->o_image_pattern(), output);
  }

  // optional bool image_compressed = 12 [default = true];
  if (has_image_compressed()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(12, this->image_compressed(), output);
  }

  // optional uint32 image_compression_type = 13 [default = 2];
  if (has_image_compression_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(13, this->image_compression_type(), output);
  }

  // optional uint32 image_type = 14 [default = 3];
  if (has_image_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(14, this->image_type(), output);
  }

  // optional uint32 byte_per_pixel = 15 [default = 1];
  if (has_byte_per_pixel()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(15, this->byte_per_pixel(), output);
  }

  // optional uint32 bit_per_pixel = 16 [default = 8];
  if (has_bit_per_pixel()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(16, this->bit_per_pixel(), output);
  }

  // optional bytes image_payload = 17;
  if (has_image_payload()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      17, this->image_payload(), output);
  }

  // optional bytes bmp_image = 18;
  if (has_bmp_image()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      18, this->bmp_image(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SensorNearData.MFC.CameraImage)
}

::google::protobuf::uint8* CameraImage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SensorNearData.MFC.CameraImage)
  // optional .Header header = 1;
  if (has_header()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->header(), target);
  }

  // optional uint32 image_counter = 2 [default = 0];
  if (has_image_counter()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->image_counter(), target);
  }

  // optional sint32 image_width = 3 [default = 1176];
  if (has_image_width()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(3, this->image_width(), target);
  }

  // optional sint32 image_height = 4 [default = 640];
  if (has_image_height()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(4, this->image_height(), target);
  }

  // optional sint32 image_shift_u = 5 [default = 0];
  if (has_image_shift_u()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(5, this->image_shift_u(), target);
  }

  // optional sint32 image_shift_v = 6 [default = 0];
  if (has_image_shift_v()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(6, this->image_shift_v(), target);
  }

  // optional sint32 o_image_width = 7 [default = 1176];
  if (has_o_image_width()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(7, this->o_image_width(), target);
  }

  // optional sint32 o_image_height = 8 [default = 640];
  if (has_o_image_height()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(8, this->o_image_height(), target);
  }

  // optional sint32 imager_size_u = 9 [default = 1280];
  if (has_imager_size_u()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(9, this->imager_size_u(), target);
  }

  // optional sint32 imager_size_v = 10 [default = 960];
  if (has_imager_size_v()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(10, this->imager_size_v(), target);
  }

  // optional uint32 o_image_pattern = 11 [default = 3];
  if (has_o_image_pattern()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(11, this->o_image_pattern(), target);
  }

  // optional bool image_compressed = 12 [default = true];
  if (has_image_compressed()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(12, this->image_compressed(), target);
  }

  // optional uint32 image_compression_type = 13 [default = 2];
  if (has_image_compression_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(13, this->image_compression_type(), target);
  }

  // optional uint32 image_type = 14 [default = 3];
  if (has_image_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(14, this->image_type(), target);
  }

  // optional uint32 byte_per_pixel = 15 [default = 1];
  if (has_byte_per_pixel()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(15, this->byte_per_pixel(), target);
  }

  // optional uint32 bit_per_pixel = 16 [default = 8];
  if (has_bit_per_pixel()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(16, this->bit_per_pixel(), target);
  }

  // optional bytes image_payload = 17;
  if (has_image_payload()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        17, this->image_payload(), target);
  }

  // optional bytes bmp_image = 18;
  if (has_bmp_image()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        18, this->bmp_image(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SensorNearData.MFC.CameraImage)
  return target;
}

int CameraImage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .Header header = 1;
    if (has_header()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->header());
    }

    // optional uint32 image_counter = 2 [default = 0];
    if (has_image_counter()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->image_counter());
    }

    // optional sint32 image_width = 3 [default = 1176];
    if (has_image_width()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->image_width());
    }

    // optional sint32 image_height = 4 [default = 640];
    if (has_image_height()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->image_height());
    }

    // optional sint32 image_shift_u = 5 [default = 0];
    if (has_image_shift_u()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->image_shift_u());
    }

    // optional sint32 image_shift_v = 6 [default = 0];
    if (has_image_shift_v()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->image_shift_v());
    }

    // optional sint32 o_image_width = 7 [default = 1176];
    if (has_o_image_width()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->o_image_width());
    }

    // optional sint32 o_image_height = 8 [default = 640];
    if (has_o_image_height()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->o_image_height());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional sint32 imager_size_u = 9 [default = 1280];
    if (has_imager_size_u()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->imager_size_u());
    }

    // optional sint32 imager_size_v = 10 [default = 960];
    if (has_imager_size_v()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->imager_size_v());
    }

    // optional uint32 o_image_pattern = 11 [default = 3];
    if (has_o_image_pattern()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->o_image_pattern());
    }

    // optional bool image_compressed = 12 [default = true];
    if (has_image_compressed()) {
      total_size += 1 + 1;
    }

    // optional uint32 image_compression_type = 13 [default = 2];
    if (has_image_compression_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->image_compression_type());
    }

    // optional uint32 image_type = 14 [default = 3];
    if (has_image_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->image_type());
    }

    // optional uint32 byte_per_pixel = 15 [default = 1];
    if (has_byte_per_pixel()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->byte_per_pixel());
    }

    // optional uint32 bit_per_pixel = 16 [default = 8];
    if (has_bit_per_pixel()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->bit_per_pixel());
    }

  }
  if (_has_bits_[16 / 32] & (0xffu << (16 % 32))) {
    // optional bytes image_payload = 17;
    if (has_image_payload()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->image_payload());
    }

    // optional bytes bmp_image = 18;
    if (has_bmp_image()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->bmp_image());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CameraImage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CameraImage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CameraImage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CameraImage::MergeFrom(const CameraImage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_header()) {
      mutable_header()->::Header::MergeFrom(from.header());
    }
    if (from.has_image_counter()) {
      set_image_counter(from.image_counter());
    }
    if (from.has_image_width()) {
      set_image_width(from.image_width());
    }
    if (from.has_image_height()) {
      set_image_height(from.image_height());
    }
    if (from.has_image_shift_u()) {
      set_image_shift_u(from.image_shift_u());
    }
    if (from.has_image_shift_v()) {
      set_image_shift_v(from.image_shift_v());
    }
    if (from.has_o_image_width()) {
      set_o_image_width(from.o_image_width());
    }
    if (from.has_o_image_height()) {
      set_o_image_height(from.o_image_height());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_imager_size_u()) {
      set_imager_size_u(from.imager_size_u());
    }
    if (from.has_imager_size_v()) {
      set_imager_size_v(from.imager_size_v());
    }
    if (from.has_o_image_pattern()) {
      set_o_image_pattern(from.o_image_pattern());
    }
    if (from.has_image_compressed()) {
      set_image_compressed(from.image_compressed());
    }
    if (from.has_image_compression_type()) {
      set_image_compression_type(from.image_compression_type());
    }
    if (from.has_image_type()) {
      set_image_type(from.image_type());
    }
    if (from.has_byte_per_pixel()) {
      set_byte_per_pixel(from.byte_per_pixel());
    }
    if (from.has_bit_per_pixel()) {
      set_bit_per_pixel(from.bit_per_pixel());
    }
  }
  if (from._has_bits_[16 / 32] & (0xffu << (16 % 32))) {
    if (from.has_image_payload()) {
      set_image_payload(from.image_payload());
    }
    if (from.has_bmp_image()) {
      set_bmp_image(from.bmp_image());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CameraImage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CameraImage::CopyFrom(const CameraImage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CameraImage::IsInitialized() const {

  return true;
}

void CameraImage::Swap(CameraImage* other) {
  if (other != this) {
    std::swap(header_, other->header_);
    std::swap(image_counter_, other->image_counter_);
    std::swap(image_width_, other->image_width_);
    std::swap(image_height_, other->image_height_);
    std::swap(image_shift_u_, other->image_shift_u_);
    std::swap(image_shift_v_, other->image_shift_v_);
    std::swap(o_image_width_, other->o_image_width_);
    std::swap(o_image_height_, other->o_image_height_);
    std::swap(imager_size_u_, other->imager_size_u_);
    std::swap(imager_size_v_, other->imager_size_v_);
    std::swap(o_image_pattern_, other->o_image_pattern_);
    std::swap(image_compressed_, other->image_compressed_);
    std::swap(image_compression_type_, other->image_compression_type_);
    std::swap(image_type_, other->image_type_);
    std::swap(byte_per_pixel_, other->byte_per_pixel_);
    std::swap(bit_per_pixel_, other->bit_per_pixel_);
    std::swap(image_payload_, other->image_payload_);
    std::swap(bmp_image_, other->bmp_image_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CameraImage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CameraImage_descriptor_;
  metadata.reflection = CameraImage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace MFC
}  // namespace SensorNearData

// @@protoc_insertion_point(global_scope)
