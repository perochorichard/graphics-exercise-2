#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Shader.h"
#include "Mesh.h"
#include "WindowController.h"
#include "Camera.h"

class GameController : public Singleton<GameController>
{
public:
	GameController();
	virtual ~GameController(){}

	void Initialize();
	void RunGame();

private:
	Shader m_shader;
	Camera m_camera;
	Mesh m_mesh;
};

#endif // !GAME_CONTROLLER_H
