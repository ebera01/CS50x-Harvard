#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp[height][width];

            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;

            image[i][(width - 1) - j].rgbtRed = temp[i][j].rgbtRed;
            image[i][(width - 1) - j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][(width - 1) - j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width); j++)
        {
            int redsum = 0;
            int greensum = 0;
            int bluesum = 0;
            int count = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int height_ = i - k;
                    int width_ = j - l;

                    if ((height_ >= 0) && (height_ < (height)) && (width_ >= 0) && (width_ < width))
                    {
                        redsum += image[height_][width_].rgbtRed;
                        bluesum += image[height_][width_].rgbtBlue;
                        greensum += image[height_][width_].rgbtGreen;
                        count++;
                    }
                }
            }
            temp[i][j].rgbtRed = round((float)redsum / count);
            temp[i][j].rgbtBlue = round((float)bluesum / count);
            temp[i][j].rgbtGreen = round((float)greensum / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width); j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    RGBTRIPLE temp[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width); j++)
        {
            int gx_red = 0;
            int gx_blue = 0;
            int gx_green = 0;
            int gy_red = 0;
            int gy_blue = 0;
            int gy_green = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int height_ = i + k;
                    int width_ = j + l;

                    if ((height_ >= 0) && (height_ < (height)) && (width_ >= 0) && (width_ < width))
                    {
                        gx_red += image[height_][width_].rgbtRed * gx[k + 1][l + 1];
                        gx_blue += image[height_][width_].rgbtBlue * gx[k + 1][l + 1];
                        gx_green += image[height_][width_].rgbtGreen * gx[k + 1][l + 1];
                        gy_red += image[height_][width_].rgbtRed * gy[k + 1][l + 1];
                        gy_blue += image[height_][width_].rgbtBlue * gy[k + 1][l + 1];
                        gy_green += image[height_][width_].rgbtGreen * gy[k + 1][l + 1];
                    }
                }
            }
            int f_red = (int) round(sqrt(pow((float) gx_red, 2) + pow((float) gy_red, 2)));
            int f_blue = (int) round(sqrt(pow((float) gx_blue, 2) + pow((float) gy_blue, 2)));
            int f_green = (int) round(sqrt(pow((float) gx_green, 2) + pow((float) gy_green, 2)));

            if (f_red > 255)
            {
                f_red = 255;
            }
            if (f_blue > 255)
            {
                f_blue = 255;
            }
            if (f_green > 255)
            {
                f_green = 255;
            }
            temp[i][j].rgbtRed = f_red;
            temp[i][j].rgbtBlue = f_blue;
            temp[i][j].rgbtGreen = f_green;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width); j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
