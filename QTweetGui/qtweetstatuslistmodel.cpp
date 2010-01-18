#include "qtweetstatuslistmodel.h"

QStringList QTweetStatusListModel::headerText = QStringList() << "Text";

QTweetStatusListModel::QTweetStatusListModel(QObject *parent) : QAbstractTableModel(parent) {
}

QTweetStatusListModel::QTweetStatusListModel(const QTweetStatusList &statuslist, QObject *parent) : QAbstractTableModel(parent) {
    statusList = statuslist;
}

void QTweetStatusListModel::setStatusList(const QTweetStatusList &statuslist) {
    statusList = statuslist;
}
QTweetStatusList QTweetStatusListModel::StatusList() const {
    return statusList;
}

QVariant QTweetStatusListModel::data(const QModelIndex & index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= statusList.size())
        return QVariant();
    if (index.column() >= QTWEETSTATUSLISTMODEL_COLUMNS)
        return QVariant();

    if (role == Qt::DisplayRole) {
        switch(index.column()) {
            case 0:return statusList.at(index.row()).text();
            default: return QVariant();
        }
    } else
        return QVariant();
}

int QTweetStatusListModel::rowCount(const QModelIndex & /*parent*/) const {
    return statusList.count();
}

int QTweetStatusListModel::columnCount(const QModelIndex & /*parent*/) const {
    return QTWEETSTATUSLISTMODEL_COLUMNS;
}

QVariant QTweetStatusListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QTweetStatusListModel::headerText.at(section);
    else
        return QVariant();
}
