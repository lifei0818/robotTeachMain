#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QString>
#include <QApplication>
#include <QDir>
#include <QProcess>
#include <QThread>
#include <QSettings>
#include "macroDefine.hpp"

#include "robotData/robotData.h"

/**
 * @brief 启动新线程
 */
class MyThread : public QObject
{ 
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    ~MyThread();

private:
    QProcess* m_myProcess;  ///< 示教器线程
    QProcess* m_updateProcess;  ///< 更新线程

    QString m_IP;  ///< 服务端IP
    QString m_Port;  ///< 服务端端口

    QString m_robotType;  ///< 示教器类型

public slots:
    void startThreadRobot();  ///< 启动示教器线程

    void startThreadUpdate();  ///< 启动更新线程

signals:
    void signalTipShow(bool);  ///< 用于提示窗口的显示与隐藏
};

#endif // MYTHREAD_H
