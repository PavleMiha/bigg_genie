/*
 * Copyright 2024 Pavle Mihajlovic. All rights reserved.
 */

#pragma once

#include <bgfx/bgfx.h>
#include "mesh.h"
#include "vertex.h"

struct Resources
{
	bgfx::ProgramHandle vertexColorProgram;
	bgfx::ProgramHandle meshProgram;
	
	Mesh teapot;
	Mesh sponza;

	const PosColorVertex cubeVertices[8] =
	{
		{-1.0f,  1.0f,  1.0f, 0xff000000 },
		{ 1.0f,  1.0f,  1.0f, 0xff0000ff },
		{-1.0f, -1.0f,  1.0f, 0xff00ff00 },
		{ 1.0f, -1.0f,  1.0f, 0xff00ffff },
		{-1.0f,  1.0f, -1.0f, 0xffff0000 },
		{ 1.0f,  1.0f, -1.0f, 0xffff00ff },
		{-1.0f, -1.0f, -1.0f, 0xffffff00 },
		{ 1.0f, -1.0f, -1.0f, 0xffffffff },
	};

	const uint16_t cubeIndexList[36] =
	{
		0, 1, 2, // 0
		1, 3, 2,
		4, 6, 5, // 2
		5, 6, 7,
		0, 2, 4, // 4
		4, 2, 6,
		1, 5, 3, // 6
		5, 7, 3,
		0, 4, 1, // 8
		4, 5, 1,
		2, 3, 6, // 10
		6, 3, 7,
	};

	bgfx::VertexBufferHandle cube_vbh;
	bgfx::IndexBufferHandle cube_ibh;

	void load_mesh_scene(const std::string& filepath);
};

bool loadResources();

extern Resources g_resources;
