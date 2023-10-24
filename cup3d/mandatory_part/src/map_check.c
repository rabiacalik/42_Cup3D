#include "cub3d.h"

//static int tanımlanmış neden !!!
// alan 1 lerle kapatılmısmı yı kontrol ediyoruz
int horizontal_check(char **map)
{
    int i;
    int j;
    int flag;

    i = -1;
    
    while (map[++i])
    {
        j = -1;
        flag = 0;

        while (map[i][++j])
        {
            if (flag == 0 && map[i][j] == '1')
                flag = 1;
            
            if (flag == 0 && ft_strchr("NESW0", map[i][j]))
                return (0);
            
            if (flag == 1 && map[i][j] == ' ')
            {
                if (map[i][j - 1] && ft_strchr("NESW0", map[i][j - 1]))
                    return (0);
                flag = 0;
            }
        }
    }
    return (1);
}

int vertical_check(char **map)
{
    int i;
    int j;
    int flag;

    j = -1;

    while (map[0][++j])
    {
        flag = 0;
        i = -1;

        while (map[++i] && map[++i][j])
        {
            if (flag == 0 && map[i][j] == '1')
                flag = 1;
            
            if (flag == 0 && ft_strchr("NESW0", map[i][j]))
                return (0);
            
            if (flag == 1 && map[i][j] == ' ')
            {
                if (map[i - 1] && map[i - 1][j] && ft_strchr("NESW0", map[i - 1][j]))
                    return (0);
                flag = 0;
            }

            // cunku en alt kısımda fazladan bosluk yok
            if (!map[i + 1] && ft_strchr("NESW0", map[i][j]))
                return (0);     
        }
    }
    return (1);
}

int map_check(char **map)
{
    if (!horizontal_check(map))
        return (0);
    
    if (!vertical_check(map))
        return (0);
    
    return (1);
}