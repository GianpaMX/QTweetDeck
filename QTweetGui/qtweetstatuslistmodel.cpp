#include <QDebug>
#include "qtweetstatuslistmodel.h"

QStringList QTweetStatusListModel::headerText =
        QStringList() << "Created At" << "ID" << "Text" << "Source" << "Truncated"
         << "In Replay to Status" << "In Replay to User" << "Favorited" << "In Replay to ScreenName" << "User";

QTweetStatusListModel::QTweetStatusListModel(QObject *parent) : QAbstractItemModel(parent) {
    statusList = new QTweetStatusList;
}

QTweetStatusListModel::QTweetStatusListModel(const QTweetStatusList &statuslist, QObject *parent) : QAbstractItemModel(parent) {
    statusList = new QTweetStatusList;
    setStatusList(statuslist);
}

QTweetStatusListModel::~QTweetStatusListModel() {
    delete statusList;
}

void QTweetStatusListModel::setStatusList(const QTweetStatusList &statuslist) {
    *statusList = statuslist;
}
QTweetStatusList QTweetStatusListModel::StatusList() const {
    return *statusList;
}

QModelIndex QTweetStatusListModel::index(int row, int column, const QModelIndex &parent) const {
    return hasIndex(row, column, parent) ? createIndex(row, column, 0) : QModelIndex();
}
QModelIndex QTweetStatusListModel::parent(const QModelIndex &index) const {
    return QModelIndex();
}

QVariant QTweetStatusListModel::data(const QModelIndex & index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= statusList->size())
        return QVariant();
    if (index.column() >= headerText.count())
        return QVariant();

    if (role == Qt::DisplayRole) {
        switch(index.column()) {
            case 0: return statusList->at(index.row()).createdAt();
            case 1: return statusList->at(index.row()).id();
            case 2: return statusList->at(index.row()).text();
            case 3: return statusList->at(index.row()).source();
            case 4: return qVariantFromValue(statusList->at(index.row()).truncated());
            case 5: return statusList->at(index.row()).inReplayToStatus()?statusList->at(index.row()).inReplayToStatus()->id():0;
            case 6: return qVariantFromValue(static_cast<void*>(statusList->at(index.row()).inReplayToUser()));
            case 7: return statusList->at(index.row()).favorited();
            case 8: return statusList->at(index.row()).inReplayToScreenName();
            case 9: return qVariantFromValue(static_cast<void*>(statusList->at(index.row()).user()));
            default: return QVariant();
        }
    } else
        return QVariant();
}

int QTweetStatusListModel::rowCount(const QModelIndex & /*parent*/) const {
    return statusList->count();
}

int QTweetStatusListModel::columnCount(const QModelIndex & /*parent*/) const {
    return headerText.count();
}

QVariant QTweetStatusListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QTweetStatusListModel::headerText.at(section);
    else
        return QVariant();
}

void QTweetStatusListModel::addStatusList(const QTweetStatusList& statuslist, const QString& error) {
    if(!error.isEmpty()) {
        emit errorModeling(error);
        return;
    }
    if(statuslist.count() <= 0)
        return;

    beginInsertRows(QModelIndex(), 0, statuslist.count()-1);
    statusList->prependReverse(statuslist);
    endInsertRows();
}
