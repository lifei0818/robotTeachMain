#include "robotData.h"

#include <QDebug>

robotData* robotData::_instance = nullptr;

robotData* robotData::Instance()
{
    if(_instance == nullptr){
        _instance = new robotData();
    }
    return _instance;
}

void robotData::setPath(QString str)
{
    m_Path = str;
}

QString robotData::getPath()
{
    return m_Path;
}

bool robotData::setIP(QString ip, QString port)
{
    std::string strIP = ip.toStdString();
    int intPort = port.toInt();

    bool state = m_client->SetIPAndPort(strIP, intPort);

    return state;
}

void robotData::getIP(QString& strIp, QString& strPort)
{
    QDir PATH = QDir(qApp->applicationDirPath());
    PATH.cd("config");
    QString pathCache = PATH.path() + QString("/Cache.ini");

    QSettings st(pathCache, QSettings::IniFormat);
    strIp = st.value("user/teacherIP").toString();
    strPort = st.value("user/teacherPort").toString();

    m_localIP = st.value("user/localIP").toString();
}

void robotData::setDownloadState(bool state)
{
    m_isDownload = state;
}

bool robotData::getDownloadState()
{
    return m_isDownload;
}

void robotData::connect()
{
    getIP(m_IP, m_Port);

    if((m_IP == QString("")) || (m_Port == QString(""))){
        emit signalShowInfo(QString("连接失败!"));
        return;
    }

    std::string strIp = m_IP.toStdString();
    int intPort = m_Port.toInt();

    if(m_client == nullptr){
        m_client = new LibEvtClient();
    }

    if(m_isFirstConnect){
        if(m_client->InitSystem(strIp, intPort) != 0){
            emit signalShowInfo(QString("连接失败!"));
        }else{
            m_isFirstConnect = false;
            emit signalShowInfo(QString("连接成功!"));
        }
    }else{
        if(m_client->TryConnect() != 0){
            emit signalShowInfo(QString("再连接失败!"));
        }else{
            emit signalShowInfo(QString("再连接成功!"));
        }
    }
}

bool robotData::getConnectState()
{
    return m_client->IsConnect();
}

void robotData::getInfo()
{
    m_class = m_client->GetClass();
    m_lesson = m_client->GetCourse();

    string str = m_client->GetClassStudent();

    QString QStr = QString::fromStdString(str);
    QStringList content = QStr.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);

    if(content.size() < 2){
        return;
    }

    for(int i = 1; i < content.size(); ++i){
        QStringList lineContent = content[i].split("\t");

        if(m_localIP == lineContent[8]){
            QString tmp = lineContent[2];

            m_student = tmp.toStdString();

            tmp = lineContent[6];

            m_deviceNum = tmp.toStdString();
            break;
        }
    }
}

void robotData::upFile(QString fileName, QString filePath, int type)
{
    getInfo();

    qDebug()<<"class"<<m_class.c_str();
    qDebug()<<"student"<<m_student.c_str();
    qDebug()<<"lesson"<<m_lesson.c_str();
    qDebug()<<"devicenum"<<m_deviceNum.c_str();

    if((m_class == std::string("")) || (m_student == std::string("")) || (m_lesson == std::string(""))
            || (m_deviceNum == std::string(""))){
        emit signalShowInfo(QString("文件信息不完整!"));
        return;
    }

    std::string name = fileName.toStdString();
    std::string path = filePath.toStdString();

    qDebug()<<"fileName  "<<fileName;
    qDebug()<<"filePath  "<<filePath;
    qDebug()<<"m_deviceNum  "<<m_deviceNum.c_str();
    qDebug()<<"type  "<<type;

//    QFile file(QString("/home/osrc/log.txt"));
//    if(!file.open(QIODevice::WriteOnly))
//    {
//        cout << "failed to open cache file" << endl;
//        exit(1);
//    }

//    QTextStream in(&file);
//    in<<QString::fromStdString(m_class)<<"\n";
//    in<<QString::fromStdString(m_student)<<"\n";
//    in<<QString::fromStdString(m_lesson)<<"\n";
//    in<<QString::fromStdString(m_deviceNum)<<"\n";
//    in<<fileName<<"\n";
//    in<<filePath<<"\n";
//    in<<type<<"\n";
//    file.close();

    m_client->UpperFile(m_class, m_student, m_lesson, name, path, m_deviceNum, type);
}

QList<QString> robotData::getFileList()
{
    getInfo();

    m_listProgram.clear();

    if((m_class == std::string("")) || (m_lesson == std::string(""))){
        emit signalShowInfo(QString("班级或课程未设置!"));
        return m_listProgram;
    }

    string str;
    m_client->GetFileList(m_class, m_student, str);

    qDebug()<<"str  "<<str.c_str();

    QString QStr = QString::fromStdString(str);
    QStringList content = QStr.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);

    for(int i = 1; i < content.size(); ++i){
        QStringList lineContent = content[i].split("\t");

        qDebug()<<"name  "<<lineContent[0];
        qDebug()<<"path  "<<lineContent[2];
        qDebug()<<"type  "<<lineContent[4];
        qDebug()<<"lesson  "<<lineContent[6];
        qDebug()<<"up or down"<<lineContent[8];
        //file
        m_listProgram.push_back(lineContent[0]);  //name
        m_listProgram.push_back(lineContent[2]);  //path
        m_listProgram.push_back(lineContent[4]);  //type
        m_listProgram.push_back(lineContent[6]);  //lesson
        m_listProgram.push_back(lineContent[8]);  //up or down
    }

    return m_listProgram;
}

void robotData::downFile(QString name)
{
    std::string path;
    std::string course;
    int type;

    int count = m_listProgram.size() / 5;

    for(int i = 0; i < count; ++i){
        if(m_listProgram[5*i] == name){
            path = m_listProgram[5*i + 1].toStdString();
            course = m_listProgram[5*i + 3].toStdString();
            type = m_listProgram[5*i + 2].toInt();

            break;
        }
    }

    qDebug()<<name;
    qDebug()<<path.c_str();
    qDebug()<<course.c_str();
    qDebug()<<type;

    m_client->DownloadFile(path, course, type, 1);
}

void robotData::showInfo(QString str)
{
    emit signalShowInfo(str);
}

void robotData::setLocalIP(QString str)
{
    m_localIP = str;
}

void robotData::setRobotType(QString str)
{
    m_robotType = str;
}

QString robotData::getRobotType()
{
    return m_robotType;
}

robotData::robotData()
{

}

robotData::~robotData()
{

}
