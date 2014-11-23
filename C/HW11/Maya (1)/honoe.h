/* 
 * File:   honoe.h
 * Author: ukod
 *
 * Created on 24 августа 2014 г., 17:00
 */

#ifndef HONOE_H
#define	HONOE_H

#include <iostream>
using namespace std;

int hanoi_towers(int disk, int from, int to, int ave)
{							
	if (disk != 0)
	{
		hanoi_towers(disk-1, from, ave, to);
 
		cout << from << " -> " << to << endl;
 
		hanoi_towers(disk-1, ave, to, from);
	}
        return 0;
}

#endif	/* HONOE_H */

