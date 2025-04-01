/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/01 13:38:25 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <minirt.h>

t_intersections	*world_intersect(t_list *solid_objs, t_ray *ray)
{
	t_intersections	*insects;
	t_object_entry	*entry;
	int				res;

	insects = ft_calloc(1, sizeof(t_intersections));
	if (!insects)
		return (0);
	while (solid_objs)
	{
		entry = solid_objs->content;
		if (entry->type == SPHERE)
			res = sphere_intersect(insects, entry, ray);
		if (!res)
		{
			clear_intersections(insects);
			return (0);
		}
		solid_objs = solid_objs->next;
	}
	return (insects);
}

t_material	*get_material(int obj_type, void *obj)
{
	t_material	*mat;

	if (obj_type == SPHERE)
		mat = &((t_sphere *)obj)->mat;
	else if (obj_type == PLANE)
		mat = &((t_plane *)obj)->mat;
	else if (obj_type == CYLINDER)
		mat = &((t_cylinder *)obj)->mat;
	return (mat);
}

typedef struct s_shader
{
	t_colors	ambient_c;
	t_colors	effect_c;
	t_colors	diffuse_c;
	t_colors	specular_c;
	t_tuple		lightv;
	t_tuple		reflectv;
	t_material	*mat;
	float		light_dot_n;
	float		reflect_dot_e;
}				t_shader;

t_colors	compute_diffuse(t_shader *shader)
{
	t_colors	diffuse_c;

	diffuse_c = colormulti_f(&shader->effect_c, shader->mat->diffuse);
	diffuse_c = colormulti_f(&diffuse_c, shader->light_dot_n);
	return (diffuse_c);
}

t_colors	compute_specular(t_shader *shader, t_light *light)
{
	float		factor;
	t_colors	specular_c;

	factor = pow(shader->reflect_dot_e, shader->mat->shininess);
	specular_c = colormulti_f(light->colors, light->ratio);
	specular_c = colormulti_f(&specular_c, shader->mat->specular);
	specular_c = colormulti_f(&specular_c, factor);
	return (specular_c);
}

t_colors	shade_hit(t_alight *alight, t_computes *comp, t_light *light)
{
	t_shader	shader;
	t_colors	res;

	shader.mat = get_material(comp->insect->obj_type, comp->insect->obj);
	shader.effect_c = colormulti_f(&shader.mat->color, light->ratio);
	shader.ambient_c = colormulti_f(&shader.mat->color, alight->ratio);
	shader.lightv = n_tuplesub(light->pos, &comp->hpoint);
	shader.lightv = tuplenormalize(&shader.lightv);
	shader.light_dot_n = tupledot(&shader.lightv, &comp->nv);
	if (shader.light_dot_n < 0)
		shader.diffuse_c = colorinit(0, 0, 0);
	else
		shader.diffuse_c = compute_diffuse(&shader);
	shader.lightv = tuplenegt(&shader.lightv);
	shader.reflectv = reflect_vec(&shader.lightv, &comp->nv);
	shader.reflect_dot_e = tupledot(&shader.reflectv, &comp->eyev);
	if (shader.reflect_dot_e <= 0)
		shader.specular_c = colorinit(0, 0, 0);
	else
		shader.specular_c = compute_specular(&shader, light);
	res = coloradd(&shader.ambient_c, &shader.diffuse_c);
	res = coloradd(&res, &shader.specular_c);
	return (res);
}

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		res;
	t_intersections	*insects;
	t_intersect		*insect;
	t_computes		comp;

	insects = world_intersect(rts->solid_objs, ray);
	insect = get_hit(insects);
	if (insect)
	{
		comp = init_computes(insect, ray);
		res = shade_hit(rts->alight, &comp,
				((t_object_entry *)rts->vision_objs->content)->object);
	}
	else
		res = colorinit(ft_fabs(ray->direction.y) * rts->alight->ratio,
			0.8 * rts->alight->ratio, 0.8 * rts->alight->ratio);
	clear_intersections(insects);
	return (res);
}

int	prep_rt_core(int ac, char **av, t_rtptr *rts)
{
	ft_bzero(rts, sizeof(t_rtptr));
	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (parser(av[1], rts))
		return (EXIT_FAILURE);
	split_objs(rts);
	if (handle_missing_objs(rts))
		return (EXIT_FAILURE);
	if (prep_objs_postparse(rts))
		return (EXIT_FAILURE);
	if (!camera_portparse(rts->camera))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	testinverse(void)
{
	t_matrix	*mat;
	t_matrix	*inv;

	mat = matrix_init(4, 4);
	set_matrix_elem(mat, 0, 0, 8);
	set_matrix_elem(mat, 0, 1, -5);
	set_matrix_elem(mat, 0, 2, 9);
	set_matrix_elem(mat, 0, 3, 2);
	set_matrix_elem(mat, 1, 0, 7);
	set_matrix_elem(mat, 1, 1, 5);
	set_matrix_elem(mat, 1, 2, 6);
	set_matrix_elem(mat, 1, 3, 1);
	set_matrix_elem(mat, 2, 0, -6);
	set_matrix_elem(mat, 2, 1, 0);
	set_matrix_elem(mat, 2, 2, 9);
	set_matrix_elem(mat, 2, 3, 6);
	set_matrix_elem(mat, 3, 0, -3);
	set_matrix_elem(mat, 3, 1, 0);
	set_matrix_elem(mat, 3, 2, -9);
	set_matrix_elem(mat, 3, 3, -4);
	matrix_debug(mat);
	inv = matrix_inverse(mat);
	matrix_debug(inv);
	free_matrix(mat);
	free_matrix(inv);
}

t_ray	ray_pixel(t_camera *cam, int x, int y)
{
	float	world_x;
	float	world_y;
	t_tuple	world_origin;
	t_tuple	world_point;
	t_ray	ray;

	world_x = cam->hwidth - ((x + 0.5) * cam->pixel_size);
	world_y = cam->hheight - ((y + 0.5) * cam->pixel_size);
	world_origin = point(0, 0, 0);
	world_point = point(world_x, world_y, -1);
	world_origin = transform_f(cam->inv_t, &world_origin);
	world_point = transform_f(cam->inv_t, &world_point);
	t_tuple	ray_direction = n_tuplesub(&world_point, &world_origin);
	ray_direction = tuplenormalize(&ray_direction);
	ray = init_ray(&world_origin, &ray_direction);
	return (ray);
}

int	main(int ac, char **av)
{
	t_rtptr		rts;
	t_ray		ray;
	t_colors	color;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	if (init_mlx(&rts))
		cleaner(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	for (int y = 0; y < HEG; y++)
	{
		for (int x = 0; x < WID; x++)
		{
			ray = ray_pixel(rts.camera, x, y);
			color = ray_color(&rts, &ray);
			mlx_put_pixel(rts.img, x, y, colorvalue(&color));
		}
	}
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
