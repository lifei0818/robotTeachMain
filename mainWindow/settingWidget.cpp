#include "settingWidget.h"

#include <QHBoxLayout>

settingWidget::settingWidget()
{
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->setStyleSheet("background-color: rgba(203, 203, 203, 40);border: 1px solid gray;");

    this->setFixedSize(100, 580);

    initUI();
    connectSignalSlot();
}

settingWidget::~settingWidget()
{

}

void settingWidget::initUI()
{
    QPixmap icon_upload(":/images/images/upload.png");
    QLabel* labelUpload = new QLabel();
    labelUpload->setFixedSize(40, 40);
    labelUpload->setPixmap(icon_upload);
    labelUpload->setScaledContents(true);

    QLabel* labelUploadText = new QLabel(tr("上传"));

    m_buttonUpload = new QPushButton();
    m_buttonUpload->setStyleSheet("background-color: rgba(203, 203, 203, 0); border: 0px solid gray;");
    m_buttonUpload->setFixedSize(100, 75);

    QVBoxLayout* layoutUpload = new QVBoxLayout(m_buttonUpload);
    layoutUpload->setContentsMargins(0, 0, 0 ,0);
    layoutUpload->setSpacing(0);

    layoutUpload->addWidget(labelUpload);
    layoutUpload->addWidget(labelUploadText);

    QPixmap icon_download(":/images/images/download.png");
    QLabel* labelDownload = new QLabel();
    labelDownload->setFixedSize(40, 40);
    labelDownload->setPixmap(icon_download);
    labelDownload->setScaledContents(true);

    QLabel* labelDownloadText = new QLabel(tr("下载"));

    m_buttonDownload = new QPushButton();
    m_buttonDownload->setStyleSheet("background-color: rgba(203, 203, 203, 0); border: 0px solid gray;");
    m_buttonDownload->setFixedSize(100, 75);

    QVBoxLayout* layoutDownload = new QVBoxLayout(m_buttonDownload);
    layoutDownload->setContentsMargins(0, 0, 0 ,0);
    layoutDownload->setSpacing(0);

    layoutDownload->addWidget(labelDownload);
    layoutDownload->addWidget(labelDownloadText);

    QPixmap icon_connect(":/images/images/connection.png");
    m_labelConnect = new QLabel();

    m_labelConnect->setStyleSheet("background-color: red;");

    m_labelConnect->setFixedSize(40, 40);
    m_labelConnect->setPixmap(icon_connect);
    m_labelConnect->setScaledContents(true);

    QLabel* labelConnectText = new QLabel(tr("连接"));
    m_buttonConnect = new QPushButton();
    m_buttonConnect->setStyleSheet("background-color: rgba(203, 203, 203, 0); border: 0px solid gray;");
    m_buttonConnect->setFixedSize(100, 75);

    QVBoxLayout* layoutConnect = new QVBoxLayout(m_buttonConnect);
    layoutConnect->setContentsMargins(0, 0, 0 ,0);
    layoutConnect->setSpacing(0);

    layoutConnect->addWidget(m_labelConnect);
    layoutConnect->addWidget(labelConnectText);

    QPixmap icon_update(":/images/images/update.png");
    QLabel* labelUpdate = new QLabel();
    labelUpdate->setFixedSize(40, 40);
    labelUpdate->setPixmap(icon_update);
    labelUpdate->setScaledContents(true);

    QLabel* labelUpdateText = new QLabel(tr("更新"));

    m_buttonUpdate = new QPushButton();
    m_buttonUpdate->setStyleSheet("background-color: rgba(203, 203, 203, 0); border: 0px solid gray;");
    m_buttonUpdate->setFixedSize(100, 75);

    QVBoxLayout* layoutUpdate = new QVBoxLayout(m_buttonUpdate);
    layoutUpdate->setContentsMargins(0, 0, 0 ,0);
    layoutUpdate->setSpacing(0);

    layoutUpdate->addWidget(labelUpdate);
    layoutUpdate->addWidget(labelUpdateText);

    QPixmap icon_log(":/images/images/updatelog.png");
    QLabel* labelLog = new QLabel();
    labelLog->setFixedSize(40, 40);
    labelLog->setPixmap(icon_log);
    labelLog->setScaledContents(true);

    QLabel* labelLogText = new QLabel(tr("日志"));

    m_buttonLog = new QPushButton();
    m_buttonLog->setStyleSheet("background-color: rgba(203, 203, 203, 0); border: 0px solid gray;");
    m_buttonLog->setFixedSize(100, 75);

    QVBoxLayout* layoutLog = new QVBoxLayout(m_buttonLog);
    layoutLog->setContentsMargins(0, 0, 0 ,0);
    layoutLog->setSpacing(0);

    layoutLog->addWidget(labelLog);
    layoutLog->addWidget(labelLogText);

    QPixmap icon_setting(":/images/images/settings.png");
    QLabel* labelSetting = new QLabel();
    labelSetting->setFixedSize(40, 40);
    labelSetting->setPixmap(icon_setting);
    labelSetting->setScaledContents(true);

    QLabel* labelSettingText = new QLabel(tr("设置"));

    m_buttonSettings = new QPushButton();
    m_buttonSettings->setStyleSheet("background-color: rgba(203, 203, 203, 0); border: 0px solid gray;");
    m_buttonSettings->setFixedSize(100, 75);

    QVBoxLayout* layoutSetting = new QVBoxLayout(m_buttonSettings);
    layoutSetting->setContentsMargins(0, 0, 0 ,0);
    layoutSetting->setSpacing(0);

    layoutSetting->addWidget(labelSetting);
    layoutSetting->addWidget(labelSettingText);

    QVBoxLayout* layoutMain = new QVBoxLayout(this);
    layoutMain->setContentsMargins(25, 0, 0, 0);

    layoutMain->addWidget(m_buttonUpload);
    layoutMain->addWidget(m_buttonDownload);
    layoutMain->addWidget(m_buttonConnect);
    layoutMain->addWidget(m_buttonUpdate);
    layoutMain->addWidget(m_buttonLog);
    layoutMain->addWidget(m_buttonSettings);

    QString pathCache = robotData::Instance()->getPath() + QString("/robotTeachMain/config/Cache.ini");

    QSettings st(pathCache, QSettings::IniFormat);

    int state = st.value("user/state").toInt();

    m_timer = new QTimer(this);

    if(state != 1){
        m_buttonUpload->hide();
        m_buttonDownload->hide();
        m_buttonConnect->hide();
        m_buttonSettings->hide();
    }else if(state == 1){
        m_timer->start(1000);
    }
}

void settingWidget::connectSignalSlot()
{
    QObject::connect(m_timer, &QTimer::timeout, this, &settingWidget::updateState);

    QObject::connect(m_buttonUpload, &QPushButton::clicked, this, &settingWidget::buttonUplaodClilcked);
    QObject::connect(m_buttonDownload, &QPushButton::clicked, this, &settingWidget::buttonDownloadClicked);
    QObject::connect(m_buttonConnect, &QPushButton::clicked, this, &settingWidget::buttonConnectClicked);
    QObject::connect(m_buttonUpdate, &QPushButton::clicked, this, &settingWidget::buttonUpdateClicked);
    QObject::connect(m_buttonLog, &QPushButton::clicked, this, &settingWidget::buttonLogClicked);
    QObject::connect(m_buttonSettings, &QPushButton::clicked, this, &settingWidget::buttonSettingClicked);
}

void settingWidget::updateState()
{
    if(robotData::Instance()->getConnectState()){
        m_labelConnect->setStyleSheet("background-color: rgba(203, 203, 203, 40);");
    }else{
        m_labelConnect->setStyleSheet("background-color: red;");
    }
}

void settingWidget::buttonUplaodClilcked()
{
    robotData::Instance()->setDownloadState(false);
    this->hide();
    emit signalShowEditWidget(1);
}

void settingWidget::buttonDownloadClicked()
{
    robotData::Instance()->setDownloadState(true);
    this->hide();
    emit signalShowEditWidget(1);
}

void settingWidget::buttonConnectClicked()
{
    robotData::Instance()->connect();
}

void settingWidget::buttonUpdateClicked()
{
    this->hide();

    emit signalTipShowUpdate(true);

#ifdef Q_OS_WIN32
    QString srcPath = QFileDialog::getOpenFileName(this,tr("Open File"),"/",tr("Program Files(*.zip)"));
    if(srcPath == nullptr){
        return;
    }

    int index_l = srcPath.lastIndexOf("/");
    int index_r = srcPath.lastIndexOf(".");

    int num = index_r - index_l;

    QDir tmpPath(srcPath);
    tmpPath.cdUp();
    QString dstPath  = QString(tmpPath.path());

    JlCompress::extractDir(srcPath, dstPath);

    QString name = srcPath.mid(index_l+1,num-1);

//    dstPath  = QString(tmpPath.path()) + name + QString("/robotSoft");

    QString path = "C:";
//    CopyOrMove(dstPath,path,true);

    QProcess* copyProcess = new QProcess();
    copyProcess->setWorkingDirectory(dstPath);
    QString copyPath = dstPath + QString("update_HR_ROBOT") + QString("/update.bat");

    myProcess->startDetached(copyPath);

    qApp->quit();
#else

#endif
}

void settingWidget::buttonLogClicked()
{
    this->hide();
    emit signalShowEditWidget(2);
}

void settingWidget::buttonSettingClicked()
{
    this->hide();
    emit signalShowEditWidget(0);
}
