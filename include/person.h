/**
 * \file person.h
 * \class Person
 * \brief Handle all the data relatives to the Person entity.
 *
 *  In this class all the characteristic of the Person, all the thing it's
 * doing in a certain state, where it wants to go etc. are saved. Probably this
 * class will be later splitted in different kind of person with different
 * generic beahviour (soldiers etc.), but for now, keep it simple.
 *
 * \author Gabriele Sani (gabryatfendor@gmail.com)
 *
 * \version 0.1
 * \date 25 Aug 2017
 */

#include <cstdlib>
#include <vector>
#include <tuple>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
	public:
        int sector; /**< The kind of work the person does: 0 woodcutter, 1 farmer, 2 fisher, 3 miner*/
				char preferredTerrain; /**< Kind of terrain in which such sector works */
				int tireness; /**< How much the person can work before stopping */
        int position[2]; /**< X and Y position in the map grid */
        char underMe; /**< What kind of terrain there is under the person */
        bool working; /**< Is the person working? */
        bool moving; /**< Is the person moving? */
				vector<tuple<int, int>> pathCoordinates; /**< Path the person is following */

				/*! \brief Start fishing job*/
				/*!
					\sa fishing()
				*/
        void fishing();
				/*! \brief Start farming job*/
				/*!
					\sa farming()
				*/
        void farming();
				/*! \brief Start woodcutting job*/
				/*!
					\sa woodcutting()
				*/
        void woodcutting();
				/*! \brief Start mining job*/
				/*!
					\sa mining()
				*/
        void mining();
				/*! \brief Wrapper to call the correct kind of working function*/
				/*!
					\sa work()
				*/
        void work();
				/*! \brief Move at the next step of the path*/
				/*!
					\sa move()
				*/
				void move();
				/*! \brief Prepare the path the person will follow (to be implemented)*/
				/*!
					\sa move()
				*/
				vector<tuple<int, int>> setPath();

				Person() : sector (rand() % 4), preferredTerrain(setPreferredTerrain()),
				tireness(100), working(false), moving(false){};
        ~Person() {};
	private:
				/*! \brief Associate terrain with sector*/
				/*!
					\sa setPreferredTerrain()
				*/
				char setPreferredTerrain();
};
#endif
