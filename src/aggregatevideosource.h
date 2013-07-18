/* $BEGIN_LICENSE

This file is part of Minitube.
Copyright 2009, Flavio Tordini <flavio.tordini@gmail.com>

Minitube is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minitube is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minitube.  If not, see <http://www.gnu.org/licenses/>.

$END_LICENSE */

#ifndef AGGREGATEVIDEOSOURCE_H
#define AGGREGATEVIDEOSOURCE_H

#include <QtCore>
#include "videosource.h"

class AggregateVideoSource : public VideoSource {

    Q_OBJECT

public:
    AggregateVideoSource(QObject *parent = 0);
    void loadVideos(int max, int skip);
    virtual void abort();
    virtual const QStringList & getSuggestions();
    QString getName() { return name; }
    void setName(QString name) { this->name = name; }
    void setUnwatched(bool enable) { unwatched = enable; }

private:
    QString name;
    bool unwatched;

};

#endif // AGGREGATEVIDEOSOURCE_H