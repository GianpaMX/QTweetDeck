#include "qtweetcolumntitle.h"

QTweetColumnTitle::QTweetColumnTitle(const QString &title, QWidget * parent) :QWidget(parent) {
    columnTitle = new QLabel(title);
    layout = new QHBoxLayout;
    layout->addWidget(columnTitle);
    setLayout(layout);
}

QTweetColumnTitle::~QTweetColumnTitle() {
    if(columnTitle) delete columnTitle;
    if(layout) delete layout;
}

QString QTweetColumnTitle::title() const {
    return columnTitle->text();
}
void QTweetColumnTitle::setTitle(const QString &title) {
    columnTitle->setText(title);
}
