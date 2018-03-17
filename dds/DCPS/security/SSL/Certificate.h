/*
 * Distributed under the DDS License.
 * See: http://www.DDS.org/license.html
 */

#ifndef OPENDDS_SECURITY_SSL_CERTIFICATE_H
#define OPENDDS_SECURITY_SSL_CERTIFICATE_H

#include "dds/DCPS/security/DdsSecurity_Export.h"
#include "dds/DCPS/unique_ptr.h"
#include "dds/DdsDcpsCoreC.h"
#include <string>
#include <vector>
#include <iostream>
#include <openssl/x509.h>

namespace OpenDDS {
  namespace Security {
    namespace SSL {

      class SignedDocument;

      class DdsSecurity_Export Certificate
      {
      public:
        friend class SignedDocument;

        typedef DCPS::unique_ptr<Certificate> unique_ptr;

        friend DdsSecurity_Export
        std::ostream& operator<<(std::ostream&, const Certificate&);

        friend DdsSecurity_Export
        bool operator==(const Certificate& lhs, const Certificate& rhs);

        Certificate(const std::string& uri, const std::string& password = "");

        Certificate(const DDS::OctetSeq& src);

        Certificate();

        ~Certificate();

        Certificate& operator=(const Certificate& rhs);

        void load(const std::string& uri, const std::string& password = "");

        int validate(Certificate& ca, unsigned long int flags = 0u) const;

        int verify_signature(const DDS::OctetSeq& src, const std::vector<const DDS::OctetSeq*>& expected_contents);

        int subject_name_to_str(std::string& dst, unsigned long flags = XN_FLAG_ONELINE) const;

        int subject_name_digest(std::vector<unsigned char>& dst) const;

        int algorithm(std::string& dst) const;

        int serialize(std::vector<unsigned char>& dst) const;

        int serialize(DDS::OctetSeq& dst) const;

        int deserialize(const DDS::OctetSeq& src);

        const DDS::OctetSeq& original_bytes() const
        {
          return original_bytes_;
        }

        const char* dsign_algo() const
        {
          return "RSASSA-PSS-SHA256";
        }

      private:

        void load_cert_bytes(const std::string& path);

        static X509* x509_from_pem(const std::string& path, const std::string& password = "");
        static X509* x509_from_pem(const DDS::OctetSeq& bytes, const std::string& password = "");

        X509* x_;
        DDS::OctetSeq original_bytes_;
      };

      DdsSecurity_Export
      std::ostream& operator<<(std::ostream&, const Certificate&);

      DdsSecurity_Export
      bool operator==(const Certificate& lhs, const Certificate& rhs);
    }
  }
}

#endif