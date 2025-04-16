/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:35:39 by bismail           #+#    #+#             */
/*   Updated: 2025/04/15 16:00:23 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <rays.h>

/*
Ct = Center of TOP circle of Cylinder.
Cb = Center of BOTTOM circle of Cylinder.
CS = The distance between top and bottom "HEIGHT OF THE Cylinder"
Ca = normal vector for CS
Hp = hit position: a point that we presume is on the cylinder's Curved Surface
Hs, hit spine positiom. the hit position projected onto Cs
Form = ((HP - CB) * Ca) Ca + Cb

Ho the height offset from our cylinder equations; this is the distance from Hs to Cb
Form = | HS - Cb |

*/
/*
I need to check if there is a PLANE intersection in this area, then limit the intersecion to the Radius of the Disk
*/

int     disk_intersection(t_intersections *insects, t_object_entry *object, t_ray *ray)
{
       t_plane *topdisk;
        
       topdisk = (t_plane *)object;
       topdisk->pos
       check_plane_intersect((t_plane *)object, ray);


}
int	cylinder_intersect(t_intersections *insects, t_object_entry *object, t_ray *ray)
{
        /*
                Approach:
                1- 
        */
}

