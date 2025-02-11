#pragma once

typedef struct Grid Grid;

typedef struct {  
    int width;
    int height;
    int offset;
    int peakheight;
    int flatness;
} TerrainData;

void terrain_generate(Grid* terrain, TerrainData data);