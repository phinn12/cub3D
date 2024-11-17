#include "cub3d.h"

int check_texture(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (-1);
    close(fd);
    return (0);
}

int check_rgb_values(char *rgb)
{
    char **colors;
    int value;
    int i;

    colors = ft_split(rgb, ',');
    if (!colors)
        return (-1);
    for (i = 0; colors[i]; i++)
    {
        value = ft_atoi(colors[i]);
        if (value < 0 || value > 255)
        {
            freedouble(colors);
            return (-1);
        }
    }
    freedouble(colors);
    if (i != 3)
        return (-1);
    return (0);
}
int parse_and_validate_variables(char **lines, t_map_info *map_info)
{
    char **tokens;
    int i = 0;
    int texture_or_color_checked = 0;
    int line_count = 0;

    while (lines[i])
    {
        if (lines[i][0] == '\0' || lines[i][0] == '\n') {
            i++;
            continue;
        }

        tokens = ft_split(lines[i], ' ');

        if (!tokens || !tokens[0] || (tokens[0][0] == '\0')) {
            printf("Hata: Boş satır veya hatalı token bulundu: '%s'\n", lines[i]);
            freedouble(tokens);
            return (-1);
        }

        if ((tokens[0][0] == 'N' || tokens[0][0] == 'S' || tokens[0][0] == 'W' || tokens[0][0] == 'E' ||
            tokens[0][0] == 'F' || tokens[0][0] == 'C') && line_count < 6)
        {
            set_texture_or_color(tokens, map_info);
            texture_or_color_checked = 1;
        }
        else if (tokens[0][0] == '1' || tokens[0][0] == '0') {
            if (!texture_or_color_checked) {
                printf("Hata: Harita başlamadan önce texture/renk bilgisi eksik!\n");
                freedouble(tokens);
                return (-1);
            }
        }
        freedouble(tokens);
        i++;
        line_count++;

        if (line_count >= 6) {
            texture_or_color_checked = 1;
        }
    }

    return check_map_textures_and_colors(map_info);
}



int check_map_textures_and_colors(t_map_info *map_info)
{
    printf("Texture ve renk bilgileri kontrol ediliyor...\n");

    if (!map_info->north_texture || !map_info->west_texture ||
        !map_info->south_texture || !map_info->east_texture) 
    {
        printf("Eksik texture dosyası!\n");
        return -1;
    }

    if (ft_atoi(map_info->floor_color) == -1 || ft_atoi(map_info->ceiling_color) == -1) 
    {
        printf("Eksik renk bilgisi! Floor: %s, Ceiling: %s\n", map_info->floor_color, map_info->ceiling_color);
        return -1;
    }

    printf("Tüm texture ve renk bilgileri geçerli.\n");
    return 0;
}


void set_texture_or_color(char **tokens, t_map_info *map_info)
{
    printf("Ayarlanan değer: %s, %s\n", tokens[0], tokens[1]);

    if (ft_strcmp(tokens[0], "NO") == 0)
        map_info->north_texture = ft_strdup(tokens[1]);
    else if (ft_strcmp(tokens[0], "SO") == 0)
        map_info->south_texture = ft_strdup(tokens[1]);
    else if (ft_strcmp(tokens[0], "WE") == 0)
        map_info->west_texture = ft_strdup(tokens[1]);
    else if (ft_strcmp(tokens[0], "EA") == 0)
        map_info->east_texture = ft_strdup(tokens[1]);
    else if (ft_strcmp(tokens[0], "F") == 0)
        map_info->floor_color = ft_strdup(tokens[1]);
    else if (ft_strcmp(tokens[0], "C") == 0)
        map_info->ceiling_color = ft_strdup(tokens[1]);
}


void freedouble(char **array)
{
    int i;

    if (!array)
        return;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char **read_lines_from_file(int fd)
{
    char **lines = malloc(sizeof(char *) * 10000);
    char *line;
    int i = 0;

    while ((line = get_next_line(fd)) != NULL) {
        lines[i] = line;
        i++;
    }
    lines[i] = NULL;
    return lines;
}

