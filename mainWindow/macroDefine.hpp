#ifndef MACRODEFINE_H
#define MACRODEFINE_H

#include <QString>
/**
 * @brief 示教器程序名定义
 */
#ifdef _WIN32
#define robotTeachHR QString("robotTeachADJUSTMENT.exe")
#define robotTeachABB QString("robotTeachABB.exe")
#define robotTeachKUKA QString("robotTeachKUKA.exe")
#define robotTeachFNK QString("robotTeachFANUC.exe")
#define robotTeachAC QString("robotTeachYASKAWA.exe")
#else
#define robotTeachEFT QString("robotTeachADJUSTMENT")
#define robotTeachHR QString("robotTeachHR")
#define robotTeachABB QString("robotTeachABB")
#define robotTeachKUKA QString("robotTeachKUKA")
#define robotTeachFNK QString("robotTeachFANUC")
#define robotTeachAC QString("robotTeachYASKAWA")
#endif

#endif
