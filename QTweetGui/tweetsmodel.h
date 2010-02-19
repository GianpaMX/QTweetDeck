#ifndef TWEETSMODEL_H
#define TWEETSMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

#include "qtweetcore.h"
#include "qtweetgui.h"
#include "QTweetGui_global.h"

class QTWEETGUISHARED_EXPORT QTweet::TweetsModel : public QAbstractTableModel {
  Q_OBJECT
  public:
    explicit TweetsModel(AbstractUpdatableClient *client, QObject *parent = 0);
    virtual ~TweetsModel();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
  signals:
  public slots:
  protected slots:
    void appendData(Tweets *new_data);
    void prependData(Tweets *new_data);
  private:
    AbstractUpdatableClient *client;
    Tweets *tweets;

    static QStringList header_data;
};

#endif // TWEETSMODEL_H
