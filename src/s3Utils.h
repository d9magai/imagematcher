/*
 * s3Utils.h
 *
 *  Created on: 2015/10/12
 *      Author: d9magai
 */

#ifndef S3UTILS_H_
#define S3UTILS_H_

#include <aws/s3/S3Client.h>
#include <aws/core/auth/AWSCredentialsProvider.h>
#include <aws/core/utils/StringUtils.h>
#include "commons.h"

namespace d9magai {
namespace s3utils {

Aws::S3::S3Client getS3client() {

    Aws::Client::ClientConfiguration config;
    config.scheme = Aws::Http::Scheme::HTTPS;
    config.connectTimeoutMs = 30000;
    config.requestTimeoutMs = 30000;
    config.region = Aws::Region::AP_NORTHEAST_1;
    return Aws::S3::S3Client(Aws::Auth::AWSCredentials(d9magai::commons::AWS_ACCESS_KEY_ID, d9magai::commons::AWS_SECRET_ACCESS_KEY), config);
}

}
}

#endif /* S3UTILS_H_ */
