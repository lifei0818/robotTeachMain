#include "MyThread.h"

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    m_myProcess = nullptr;
}

MyThread::~MyThread()
{
    emit signalTipShow(false);
}

void MyThread::startThreadRobot()
{
    QDir PATH = QDir(qApp->applicationDirPath());
    QString path_cache = PATH.path() + QString("/config/Cache.ini");
    QSettings st(path_cache, QSettings::IniFormat);
    m_IP = st.value("user/IP").toString();
    m_Port = st.value("user/Port").toString();

    m_robotType = robotData::Instance()->getRobotType();

    PATH.cdUp();

    QString typeDir;
    int num = m_robotType.indexOf(".");
    if(num != -1){
        typeDir = m_robotType.mid(0,num);
    }else{
        typeDir = m_robotType;
    }

    QString path = PATH.path() + QString("/") + typeDir + QString("/") + m_robotType + QString(" %1 %2 -nograb").arg(m_IP).arg(m_Port);

    if(m_myProcess == nullptr)
    {
        m_myProcess = new QProcess(this);
        m_myProcess->start(path);
        connect(m_myProcess,SIGNAL(finished(int)),this,SLOT(deleteLater()));
    }
}

void MyThread::startThreadUpdate()
{
    QString command = QString("sudo ") + robotData::Instance()->getPath()
            + QString("/robotTeachMain/update.sh");

    m_updateProcess = new QProcess(this);
    m_updateProcess->startDetached(command);
    m_updateProcess->waitForFinished(-1);
}
