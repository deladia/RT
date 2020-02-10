/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:19:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/10 14:51:17 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_sphere_json(t_key_value *obj, t_sphere *sphere)
{
	double		value;
	t_array		*pos;

	if (get_double(obj, "radius", &value))
		ft_error("Error get_double: radius");
	sphere->radius = (float)value;
	if (get_array(obj, "center", &pos))
		ft_error("Error get_array: center");
	parse_array_of_float(pos, &sphere->center);
}

void			parse_plane_json(t_key_value *obj, t_plane *plane)
{
	double		value;
	t_array		*pos;

	if (get_array(obj, "axis", &pos))
		ft_error("Error get_array: axis");
	parse_array_of_float(pos, &plane->axis);
	cl_normalize(&plane->axis);
	if (get_double(obj, "dist", &value))
		ft_error("Error get_double: dist");
	plane->dist = value;
}

void			parse_cone_json(t_key_value *obj, t_cone *cone)
{
	double		value;
	t_array		*pos;

	if (get_array(obj, "center", &pos))
		ft_error("Error get_array: center");
	parse_array_of_float(pos, &cone->center);
	if (get_array(obj, "axis", &pos))
		ft_error("Error get_array: axis");
	parse_array_of_float(pos, &cone->axis);
	cl_normalize(&cone->axis);
	if (get_double(obj, "length", &value))
		ft_error("Error get_double: length");
	cone->length = (float)value;
	if (get_double(obj, "tan", &value))
		ft_error("Error get_double: tan");
	cone->tan = (float)value;
}

void			parse_cylinder_json(t_key_value *obj, t_cylinder *cylinder)
{
	double		value;
	t_array		*pos;

	if (get_array(obj, "center", &pos))
		ft_error("Error get_array: center");
	parse_array_of_float(pos, &cylinder->center);
	if (get_array(obj, "axis", &pos))
		ft_error("Error get_array: axis");
	parse_array_of_float(pos, &cylinder->axis);
	cl_normalize(&cylinder->axis);
	if (get_double(obj, "length", &value))
		ft_error("Error get_double: length");
	cylinder->length = (float)value;
	if (get_double(obj, "radius", &value))
		ft_error("Error get_double: radius");
	cylinder->radius = value;
}

void			parse_parab_json(t_key_value *obj, t_parab *parab)
{
	double		value;
	t_array		*pos;

	if (get_array(obj, "center", &pos))
		ft_error("Error get_array: center");
	parse_array_of_float(pos, &parab->center);
	if (get_array(obj, "axis", &pos))
		ft_error("Error get_array: axis");
	parse_array_of_float(pos, &parab->axis);
	cl_normalize(&parab->axis);
	if (get_double(obj, "distance", &value))
		ft_error("Error get_double: distance");
	parab->k = (float)value;
	if (get_double(obj, "length", &value))
		ft_error("Error get_double: distance");
	parab->length = (float)value;
}

void			parse_torus_json(t_key_value *obj, t_torus *tor)
{
	double		value;
	t_array		*pos;

	if (get_array(obj, "center", &pos))
		ft_error("Error get_array: center");
	parse_array_of_float(pos, &tor->center);
	if (get_array(obj, "axis", &pos))
		ft_error("Error get_array: axis");
	parse_array_of_float(pos, &tor->axis);
	cl_normalize(&tor->axis);
	if (get_double(obj, "bigr", &value))
		ft_error("Error get_double: bigr");
	tor->bigr = (float)value;
	if (get_double(obj, "r", &value))
		ft_error("Error get_double: r");
	tor->r = (float)value;
}
