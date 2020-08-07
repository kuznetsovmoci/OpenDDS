#ifndef OPENDDS_RTPS_TYPE_LOOKUP_H_
#define OPENDDS_RTPS_TYPE_LOOKUP_H_

/*
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "RtpsRpcTypeSupportImpl.h"
#include <dds/DCPS/XTypes/TypeObject.h>

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace OpenDDS {
  namespace XTypes {

    const CORBA::ULong TypeLookup_getTypes_HashId = 25318099U;
    const CORBA::ULong TypeLookup_getDependencies_HashId = 95091505U;

    struct TypeLookup_getTypes_In
    {
      TypeIdentifierSeq type_ids;

      TypeLookup_getTypes_In() {}
    };

    struct  TypeLookup_getTypes_Out
    {
      OpenDDS::XTypes::TypeIdentifierTypeObjectPairSeq types;
      OpenDDS::XTypes::TypeIdentifierPairSeq complete_to_minimal;

      TypeLookup_getTypes_Out() {}
    };

    struct  TypeLookup_getTypes_Result
    {
      OpenDDS::XTypes::TypeLookup_getTypes_Out result;

      TypeLookup_getTypes_Result() {}
    };

    typedef CORBA::Octet ContinuationPoint[32];

    struct  TypeLookup_getTypeDependencies_In
    {
      OpenDDS::XTypes::TypeIdentifierSeq type_ids;
      OpenDDS::XTypes::ContinuationPoint continuation_point;

      TypeLookup_getTypeDependencies_In() {}
    };

    struct  TypeLookup_getTypeDependencies_Out
    {
      OpenDDS::XTypes::TypeIdentifierWithSizeSeq dependent_typeids;
      OpenDDS::XTypes::ContinuationPoint continuation_point;

      TypeLookup_getTypeDependencies_Out() {}
    };

    struct  TypeLookup_getTypeDependencies_Result
    {
      OpenDDS::XTypes::TypeLookup_getTypeDependencies_Out result;

      TypeLookup_getTypeDependencies_Result() {}
    };

    struct TypeLookup_Call
    {
      CORBA::ULong kind;
      OpenDDS::XTypes::TypeLookup_getTypes_In getTypes;
      OpenDDS::XTypes::TypeLookup_getTypeDependencies_In getTypeDependencies;

      TypeLookup_Call() {}
    };

    struct TypeLookup_Request
    {
      DDS::rpc::RequestHeader header;
      OpenDDS::XTypes::TypeLookup_Call data;

      TypeLookup_Request() {}
    };

    struct TypeLookup_Return
    {
      CORBA::ULong kind;
      OpenDDS::XTypes::TypeLookup_getTypes_Result getTypes;
      OpenDDS::XTypes::TypeLookup_getTypeDependencies_Result getTypeDependencies;

      TypeLookup_Return() {}
    };

    struct TypeLookup_Reply
    {
      DDS::rpc::ResponseHeader header;
      OpenDDS::XTypes::TypeLookup_Return data;

      TypeLookup_Reply() {}
    };
  } // namespace XTypes

  namespace DCPS {

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_getTypes_In& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_getTypes_In& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_getTypes_In& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_getTypes_Out& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_getTypes_Out& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_getTypes_Out& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_getTypes_Result& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_getTypes_Result& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_getTypes_Result& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::ContinuationPoint& arr);
    bool operator<<(DCPS::Serializer& ser, const XTypes::ContinuationPoint& arr);
    bool operator>>(DCPS::Serializer& ser, XTypes::ContinuationPoint& arr);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_getTypeDependencies_In& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_getTypeDependencies_In& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_getTypeDependencies_In& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_getTypeDependencies_Out& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_getTypeDependencies_Out& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_getTypeDependencies_Out& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_getTypeDependencies_Result& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_getTypeDependencies_Result& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_getTypeDependencies_Result& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_Call& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_Call& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_Call& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_Request& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_Request& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_Request& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_Return& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_Return& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_Return& stru);

    void serialized_size(const DCPS::Encoding& encoding, size_t& size,
      const XTypes::TypeLookup_Reply& stru);
    bool operator<<(DCPS::Serializer& strm, const XTypes::TypeLookup_Reply& stru);
    bool operator>>(DCPS::Serializer& strm, XTypes::TypeLookup_Reply& stru);
  } // namespace DCPS
} // namespace OpenDDS

OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif /* ifndef OPENDDS_RTPS_TYPE_LOOKUP_H_ */
