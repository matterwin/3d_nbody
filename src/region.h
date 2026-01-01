#ifndef REGION_H
#define REGION_H 

/*
 * Oct tree regions
 * (Shown below are 2 cubes representing:
 * U - up
 * D - down
 * Note we are missing 6 other cubes in the
 * graphic to complete the oct tree)
 *
 * Regions are with respect to looking down at the cube 
 * (Up level or the top most level is what you see first)
 * These levels are partitioned into 2d regions: NE, NW, SE, SW
 * Thus, there are 2 levels: U and D, to make 8 regions in total.
 *
 * Another way of looking at this is indexing the first level as index 0
 * and conceding levels index 1, 2, and so on.
 *
 *        //////////////////
 *       //               //
 *      / /              / /
 *     /  /             /  /
 *    /   /            /   /
 *   /    /           /    /
 *  //////////////////     /
 *  /     /          /     /
 *  /     //////////////////
 *  /    /           /    //
 *  /   /            /   / /     
 *  /  /             /  /  /    
 *  / /              / /   /   
 *  //               //    /  
 *  //////////////////     /  
 *  /                /     / 
 *  /                /     /
 *  /                /    /
 *  /                /   /
 *  /                /  /
 *  /                / /
 *  /                //
 *  //////////////////
 *
 */
enum Region
{
    NONE=-1,     // root cube
    NEU,
    NWU,
    SEU,
    SWU,
    NED,
    NWD,
    SED,
    SWD,
};

#endif
