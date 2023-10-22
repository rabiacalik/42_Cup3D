#include <cub3d.h>

int ft_strrcmp(char *src, char *dest)
{
    int src_i;
    int dest_i;

    src_i = ft_strlen(src) - ft_strlen(dest);
    dest_i = 0;

    if(src_i <= 0)
        return (0);
    
    while (src[src_i] && dest[dest_i])
    {
        if (src[src_i] != dest[dest_i])
            break;
        
        src_i++;
        dest_i++;
    }
    return ( ((unsigned char *)src)[src_i] - ((unsigned char *)dest)[dest_i]);
    
}
/*
    map.cup 7
    .cup    4
    7 - 4 = 3

*/