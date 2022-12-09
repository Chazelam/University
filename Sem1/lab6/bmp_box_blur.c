//
// Created by markg on 06.12.2021.
//

#include "bmp.h"

/*
 * Преобразует цвета пикселей в черно-белую гамму
 * (30% красного + 59% зеленого + 11% синего)
*/
void bmp_box_blur(bmp_image image)
{
    long int i, j;

    /* Получаем линейные размеры изображения */
    long int w = image.header.width;
    long int h = image.header.height;

    /* Для всех строк пикселей */
    for (i = 0; i < h; i++) {
        /* Для каждого пикселя */
        for(j = 0; j < w; j++) {

            double blue;
            double green;
            double red;

            double blue_sum = 0;
            double green_sum = 0;
            double red_sum = 0;
            for (int m = i - 2; m < i + 3; m++) {
                for (int n = j - 2; n < j + 3; n++) {
                    blue = image.pixel_array[0 * h * w + m * w + n];
                    green = image.pixel_array[1 * h * w + m * w + n];
                    red = image.pixel_array[2 * h * w + m * w + n];

                    if (i <= 1 || j <= 1 || w - j <= 2 || h - i <= 2) {
                        blue = image.pixel_array[0 * h * w + i * w + j];
                        green = image.pixel_array[1 * h * w + i * w + j];
                        red = image.pixel_array[2 * h * w + i * w + j];
                    }
                    blue_sum += blue;
                    green_sum += green;
                    red_sum += red;
                }
            }

            blue_sum /= 25;
            green_sum /= 25;
            red_sum /= 25;

            image.new_pixel_array[0 * h * w + i * w + j] = blue_sum;
            image.new_pixel_array[1 * h * w + i * w + j] = green_sum;
            image.new_pixel_array[2 * h * w + i * w + j] = red_sum;
        }
    }
}
