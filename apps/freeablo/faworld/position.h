#ifndef POSITION_H
#define POSITION_H

#include <utility>
#include <stdlib.h>
#include <stdint.h>
#include <cmath>
#include "../fasavegame/savegame.h"

#include <misc/misc.h>

namespace FAWorld
{
    class Position
    {
        public:
            Position();
            Position(size_t x, size_t y);
            Position(size_t x, size_t y, size_t direction);

            void update(); ///< advances towards mNext
            
            std::pair<size_t, size_t> current() const; ///< where we are coming from
            std::pair<size_t, size_t> next() const; ///< where we are going to
            
            size_t mDist; ///< percentage of the way there

            int32_t mDirection;
            bool mMoving;
            double distanceFrom(Position B);

        
        private:
            std::pair<size_t, size_t> mCurrent;

            template<class Archive>
            void save(Archive & ar, const unsigned int version) const
            {
                UNUSED_PARAM(version);

                ar << mDirection;
                ar << mCurrent;
            }

            template<class Archive>
            void load(Archive & ar, const unsigned int version)
            {
                UNUSED_PARAM(version);

                ar >> mDirection;
                ar >> mCurrent;
                mMoving = false;
                mDist = 0;
            }


            friend class boost::serialization::access;

            BOOST_SERIALIZATION_SPLIT_MEMBER()

    };
}

#endif