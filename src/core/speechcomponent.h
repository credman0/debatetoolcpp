/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2019  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SPEECHCOMPONENT_H
#define SPEECHCOMPONENT_H

#include<QList>
#include<QVariant>
#include<QtDebug>
#include "../google-diff-match-patch/diff_match_patch.h"
#include "uuid.h"

enum SpeechComponentType {card, analytic, block, speech};

/**
 * @todo write docs
 */
class SpeechComponent
{
public:
    virtual QString getDisplayContent() = 0;
    virtual QString getLabel() = 0;
    
    uuid getUUID()
    {
        if (id == 0) {
            id.setRandom();
        }
        return id;
    }
    
    SpeechComponentType getType()
    {
        return type;
    }
protected:
    SpeechComponentType type;
    QList<Diff> localHistory;
private:
    uuid id;
};

#endif // SPEECHCOMPONENT_H
