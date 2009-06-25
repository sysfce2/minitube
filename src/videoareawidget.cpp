#include "videoareawidget.h"

VideoAreaWidget::VideoAreaWidget(QWidget *parent) : QWidget(parent) {
    stackedLayout = new QStackedLayout(this);
    setLayout(stackedLayout);
}

void VideoAreaWidget::setVideoWidget(QWidget *videoWidget) {
    this->videoWidget = videoWidget;
    stackedLayout->addWidget(videoWidget);
}

void VideoAreaWidget::setLoadingWidget(LoadingWidget *loadingWidget) {
    this->loadingWidget = loadingWidget;
    stackedLayout->addWidget(loadingWidget);
}

void VideoAreaWidget::showVideo() {
    stackedLayout->setCurrentWidget(videoWidget);
}

void VideoAreaWidget::showLoading(Video *video) {
    this->loadingWidget->setVideo(video);
    stackedLayout->setCurrentWidget(loadingWidget);
}

void VideoAreaWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    switch(event->button()) {
             case Qt::LeftButton:
        emit doubleClicked();
        break;
             case Qt::RightButton:

        break;
    }
}

void VideoAreaWidget::mousePressEvent(QMouseEvent *event) {
    switch(event->button()) {
             case Qt::LeftButton:
        break;
             case Qt::RightButton:
        emit rightClicked();
        break;
    }
}
