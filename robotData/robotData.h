#ifndef ROBOTDATA_H
#define ROBOTDATA_H

#include <QApplication>
#include <QString>
#include <QList>
#include <QDir>
#include <QSettings>

#include <QDebug>

#include "client.h"

/**
* @brief 教师端连接与相关数据操作
*/
class robotData : public QObject
{
    Q_OBJECT
public:
    static robotData* Instance();  ///< 单例模式

    void setPath(QString);  ///< 设置程序路径
    QString getPath();  ///< 返回程序路径

    bool setIP(QString, QString);  ///< 设置教师端IP与端口
    void getIP(QString&, QString&);  ///< 从缓存中读取IP与端口

    void setDownloadState(bool);  ///< 设置状态是上传或下载
    bool getDownloadState();  ///< 获取状态

    void connect();  ///< 连接教师端

    bool getConnectState();  ///< 获取连接状态

    void getInfo();  ///< 获取本机在教师端相关信息

    /**
     * @brief 焦点切换时键盘显示与文本内容编辑
     * @param fileName 文件名
     * @param filePath 文件路径
     * * @param type 文件类型
     */
    void upFile(QString fileName, QString filePath,int type);

    QList<QString> getFileList();  ///< 获取并返回教师端文件列表
    void downFile(QString);  ///< 下载文件
    void showInfo(QString);  ///< 发送提示信息信号

    void setLocalIP(QString);

    void setRobotType(QString);
    QString getRobotType();

private:
    robotData();
    ~robotData();

private:
    QString m_Path;  ///< 程序路径

    std::string m_class;  ///< 班级
    std::string m_student;  ///< 课程
    std::string m_lesson;  ///< 学生

    QString m_IP;  ///< 服务端IP
    QString m_Port;  ///< 服务端端口

    QString m_localIP;  ///< 本机IP
    std::string m_deviceNum;  ///< 本机设备编号

    QList<QString> m_listProgram;  ///< 保存文件信息

    bool m_isFirstConnect = true;  ///< 判断是否第一次连接
    bool m_isDownload = false;  ///< 判断上传或是下载

    QString m_robotType;

    LibEvtClient* m_client = nullptr;  ///< 教师端连接与通信的类对象

private:
    static robotData* _instance;  ///< 实例对象

signals:
    void signalShowInfo(QString);  ///< 用于显示提示信息
};

#endif // ROBOTDATA_H
