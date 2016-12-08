#include <Game.h>

bool flip = false;
int current = 1;

const float maxsize = 9;

Vector_3 vertexA(-1.0f, 1.0f, -5.0f);
Vector_3 vertexB(-1.0f, -1.0f, -5.0f);
Vector_3 vertexC(1.0f, 1.0f, -5.0f);
Vector_3 vertexD(1.0f, -1.0f, -5.0f);

Vector_3 vertexE(1.0f, -1.0f, -15.0f);
Vector_3 vertexF(1.0f, 1.0f, -15.0f);
Vector_3 vertexG(-1.0f, 1.0f, -15.0f);
Vector_3 vertexH(-1.0f, -1.0f, -15.0f);

Matrix_3 rotateMatrix, translateMatrix, scaleMatrix, scaleMinus;

sf::Keyboard input;
// Front-Top
Vector_3 vertices[] = { Vector_3(vertexC.getX(), vertexC.getY(), vertexC.getZ()),		
						Vector_3(vertexA.getX(), vertexA.getY(), vertexA.getZ()),
						Vector_3(vertexB.getX(), vertexB.getY(), vertexB.getZ()) };
float colors[] = { 1.0f, 0.0f, 0.0f,	 
				   0.0f, 1.0f, 0.0f,		
				   0.0f, 0.0f, 1.0f };
// Front-Bottom
Vector_3 fbVertices[] = { Vector_3(vertexC.getX(), vertexC.getY(), vertexC.getZ()),
						  Vector_3(vertexD.getX(), vertexD.getY(), vertexD.getZ()),
						  Vector_3(vertexB.getX(), vertexB.getY(), vertexB.getZ()) };
float fbColors[] = { 1.0f, 0.0f, 0.0f,	 
					 0.0f, 1.0f, 0.0f,	 
					 0.0f, 0.0f, 1.0f };
// Back-Top
Vector_3 btVertices[] = { Vector_3(vertexG.getX(), vertexG.getY(), vertexG.getZ()),
						  Vector_3(vertexF.getX(), vertexF.getY(), vertexF.getZ()),
						  Vector_3(vertexE.getX(), vertexE.getY(), vertexE.getZ()) };
float btColors[] = { 1.0f, 1.0f, 0.0f,
					 1.0f, 1.0f, 0.0f,
					 1.0f, 1.0f, 0.0f };
// Back-Bottom
Vector_3 bbVertices[] = { Vector_3(vertexG.getX(), vertexG.getY(), vertexG.getZ()),
						  Vector_3(vertexH.getX(), vertexH.getY(), vertexH.getZ()),
						  Vector_3(vertexE.getX(), vertexE.getY(), vertexE.getZ()) };
float bbColors[] = { 1.0f, 1.0f, 0.0f,	 
					 1.0f, 1.0f, 0.0f,	 
					 1.0f, 1.0f, 0.0f };
// Right-Top
Vector_3 rtVertices[] = { Vector_3(vertexD.getX(), vertexD.getY(), vertexD.getZ()),
						  Vector_3(vertexC.getX(), vertexC.getY(), vertexC.getZ()),
						  Vector_3(vertexF.getX(), vertexF.getY(), vertexF.getZ()) };
float rtColors[] = { 0.0f, 1.0f, 1.0f,	 
					 0.0f, 1.0f, 1.0f,	 
					 0.0f, 1.0f, 1.0f };
// Right-Bottom
Vector_3 rbVertices[] = { Vector_3(vertexD.getX(), vertexD.getY(), vertexD.getZ()),
						  Vector_3(vertexE.getX(), vertexE.getY(), vertexE.getZ()),
						  Vector_3(vertexF.getX(), vertexF.getY(), vertexF.getZ()) };
float rbColors[] = { 0.0f, 1.0f, 1.0f,	
					 0.0f, 1.0f, 1.0f,	 
					 0.0f, 1.0f, 1.0f };
// Left-Top
Vector_3 ltVertices[] = { Vector_3(vertexA.getX(), vertexA.getY(), vertexA.getZ()),
						  Vector_3(vertexG.getX(), vertexG.getY(), vertexG.getZ()),
						  Vector_3(vertexH.getX(), vertexH.getY(), vertexH.getZ()) };
float ltColors[] = { 1.0f, 0.0f, 1.0f,	 
					 1.0f, 0.0f, 1.0f,	 
					1.0f, 0.0f, 1.0f };
// Left-Bottom
Vector_3 lbVertices[] = { Vector_3(vertexA.getX(), vertexA.getY(), vertexA.getZ()),
						  Vector_3(vertexB.getX(), vertexB.getY(), vertexB.getZ()),
						  Vector_3(vertexH.getX(), vertexH.getY(), vertexH.getZ()) };
float lbColors[] = { 1.0f, 0.0f, 1.0f,	 
					 1.0f, 0.0f, 1.0f,	 
					 1.0f, 0.0f, 1.0f };
// Top-Top
Vector_3 ttVertices[] = { Vector_3(vertexA.getX(), vertexA.getY(), vertexA.getZ()),
						  Vector_3(vertexG.getX(), vertexG.getY(), vertexG.getZ()),
					      Vector_3(vertexF.getX(), vertexF.getY(), vertexF.getZ()) };
float ttColors[] = { 1.0f, 1.0f, 1.0f,	 
					 1.0f, 1.0f, 1.0f,	 
					 1.0f, 1.0f, 1.0f };
// Top-Bottom
Vector_3 tbVertices[] = { Vector_3(vertexA.getX(), vertexA.getY(), vertexA.getZ()),
						  Vector_3(vertexC.getX(), vertexC.getY(), vertexC.getZ()),
						  Vector_3(vertexF.getX(), vertexF.getY(), vertexF.getZ()) };
float tbColors[] = { 1.0f, 1.0f, 1.0f,	
					 1.0f, 1.0f, 1.0f,	 
					 1.0f, 1.0f, 1.0f };
// Bottom-Top
Vector_3 bbtVertices[] = { Vector_3(vertexB.getX(), vertexB.getY(), vertexB.getZ()),
						   Vector_3(vertexH.getX(), vertexH.getY(), vertexH.getZ()),
						   Vector_3(vertexE.getX(), vertexE.getY(), vertexE.getZ()) };
float bbtColors[] = { 0.5f, 0.5f, 0.5f,	 
					  0.5f, 0.5f, 0.5f,	 
					  0.5f, 0.5f, 0.5f };
// Bottom-Bottom
Vector_3 bbbVertices[] = { Vector_3(vertexB.getX(), vertexB.getY(), vertexB.getZ()),
						   Vector_3(vertexD.getX(), vertexD.getY(), vertexD.getZ()),
						   Vector_3(vertexE.getX(), vertexE.getY(), vertexE.getZ()) };
float bbbColors[] = { 0.5f, 0.5f, 0.5f,	 
					  0.5f, 0.5f, 0.5f,	 
					  0.5f, 0.5f, 0.5f };

//
unsigned int vertex_index[] = { 0, 1, 2 };


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() 
{

}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}


void Game::update()
{
	elapsed = clock.getElapsedTime();
	//
	rotateMatrix = rotateMatrix.Rotation(1);
	//
	translateMatrix = translateMatrix.Translate(4, 4);
	//
	scaleMatrix = scaleMatrix.Scale(99.5f, 99.5f);
	//
	scaleMinus = scaleMinus.Scale(-102.5f, -102.5f);

	if (sf::Keyboard::isKeyPressed(input.R) == true)
	{
		for (int i = 0; i < 3; i++)
		{
			// Front face
			vertices[i] = vertices[i] * rotateMatrix;
			fbVertices[i] = fbVertices[i] * rotateMatrix;
			// Back face
			btVertices[i] = btVertices[i] * rotateMatrix;
			bbVertices[i] = bbVertices[i] * rotateMatrix;
			// Right face
			rtVertices[i] = rtVertices[i] * rotateMatrix;
			rbVertices[i] = rbVertices[i] * rotateMatrix;
			// Left face
			ltVertices[i] = ltVertices[i] * rotateMatrix;
			lbVertices[i] = lbVertices[i] * rotateMatrix;
			// Top face
			ttVertices[i] = ttVertices[i] * rotateMatrix;
			tbVertices[i] = tbVertices[i] * rotateMatrix;
			// Bottom face
			bbtVertices[i] = bbtVertices[i] * rotateMatrix;
			bbbVertices[i] = bbbVertices[i] * rotateMatrix;
		}
	}
	if (sf::Keyboard::isKeyPressed(input.T) == true)
	{
		for (int i = 0; i < 3; i++)
		{
			// Front face
			vertices[i] = vertices[i] * -rotateMatrix;
			fbVertices[i] = fbVertices[i] * -rotateMatrix;
			// Back face					
			btVertices[i] = btVertices[i] * -rotateMatrix;
			bbVertices[i] = bbVertices[i] * -rotateMatrix;
			// Right face					
			rtVertices[i] = rtVertices[i] * -rotateMatrix;
			rbVertices[i] = rbVertices[i] * -rotateMatrix;
			// Left face					
			ltVertices[i] = ltVertices[i] * -rotateMatrix;
			lbVertices[i] = lbVertices[i] * -rotateMatrix;
			// Top face						
			ttVertices[i] = ttVertices[i] * -rotateMatrix;
			tbVertices[i] = tbVertices[i] * -rotateMatrix;
			// Bottom face
			bbtVertices[i] = bbtVertices[i] * -rotateMatrix;
			bbbVertices[i] = bbbVertices[i] * -rotateMatrix;
		}
	}
	//
	if (sf::Keyboard::isKeyPressed(input.Right) == true)
	{
		for (int i = 0; i < 3; i++)
		{
			// Front face
			vertices[i] = vertices[i] * translateMatrix;
			fbVertices[i] = fbVertices[i] * translateMatrix;
			// Back face					
			btVertices[i] = btVertices[i] * translateMatrix;
			bbVertices[i] = bbVertices[i] * translateMatrix;
			// Right face					
			rtVertices[i] = rtVertices[i] * translateMatrix;
			rbVertices[i] = rbVertices[i] * translateMatrix;
			// Left face					
			ltVertices[i] = ltVertices[i] * translateMatrix;
			lbVertices[i] = lbVertices[i] * translateMatrix;						
			// Top face						
			ttVertices[i] = ttVertices[i] * translateMatrix;
			tbVertices[i] = tbVertices[i] * translateMatrix;

			// Bottom face
			bbtVertices[i] = bbtVertices[i] * translateMatrix;
			bbbVertices[i] = bbbVertices[i] * translateMatrix;
		}
	}
	//
	if (sf::Keyboard::isKeyPressed(input.Left) == true)
	{
		for (int i = 0; i < 3; i++)
		{
			// Front face
			vertices[i] = vertices[i] * -translateMatrix;
			fbVertices[i] = fbVertices[i] * -translateMatrix;
			// Back face					
			btVertices[i] = btVertices[i] * -translateMatrix;
			bbVertices[i] = bbVertices[i] * -translateMatrix;
			// Right face					
			rtVertices[i] = rtVertices[i] * -translateMatrix;
			rbVertices[i] = rbVertices[i] * -translateMatrix;
			// Left face					
			ltVertices[i] = ltVertices[i] * -translateMatrix;
			lbVertices[i] = lbVertices[i] * -translateMatrix;
			// Top face						
			ttVertices[i] = ttVertices[i] * -translateMatrix;
			tbVertices[i] = tbVertices[i] * -translateMatrix;

			// Bottom face
			bbtVertices[i] = bbtVertices[i] * -translateMatrix;
			bbbVertices[i] = bbbVertices[i] * -translateMatrix;
		}
	}
	//
	if (sf::Keyboard::isKeyPressed(input.S) == true)
	{
		for (int i = 0; i < 3; i++)
		{
			// Front face
			vertices[i] = vertices[i] * scaleMatrix;
			fbVertices[i] = fbVertices[i] * scaleMatrix;
			// Back face					
			btVertices[i] = btVertices[i] * scaleMatrix;
			bbVertices[i] = bbVertices[i] * scaleMatrix;
			// Right face					
			rtVertices[i] = rtVertices[i] * scaleMatrix;
			rbVertices[i] = rbVertices[i] * scaleMatrix;
			// Left face					
			ltVertices[i] = ltVertices[i] * scaleMatrix;
			lbVertices[i] = lbVertices[i] * scaleMatrix;
			// Top face						
			ttVertices[i] = ttVertices[i] * scaleMatrix;
			tbVertices[i] = tbVertices[i] * scaleMatrix;
			// Bottom face
			bbtVertices[i] = bbtVertices[i] * scaleMatrix;
			bbbVertices[i] = bbbVertices[i] * scaleMatrix;
		}
	}
	//
	if (sf::Keyboard::isKeyPressed(input.D) == true)
	{
		for (int i = 0; i < 3; i++)
		{
			// Front face
			vertices[i] = vertices[i] * scaleMinus;
			fbVertices[i] = fbVertices[i] * -scaleMinus;
			// Back face						   
			btVertices[i] = btVertices[i] * -scaleMinus;
			bbVertices[i] = bbVertices[i] * -scaleMinus;
			// Right face						  
			rtVertices[i] = rtVertices[i] * -scaleMinus;
			rbVertices[i] = rbVertices[i] * -scaleMinus;
			// Left face						   
			ltVertices[i] = ltVertices[i] * -scaleMinus;
			lbVertices[i] = lbVertices[i] * -scaleMinus;
			// Top face							   
			ttVertices[i] = ttVertices[i] * -scaleMinus;
			tbVertices[i] = tbVertices[i] * -scaleMinus;
			// Bottom face
			bbtVertices[i] = bbtVertices[i] * -scaleMinus;
			bbbVertices[i] = bbbVertices[i] * -scaleMinus;
		}
	}


	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	initialize();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Front-top face
	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Front-bottom
	glVertexPointer(3, GL_FLOAT, 0, &fbVertices);
	glColorPointer(3, GL_FLOAT, 0, &fbColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Back-top face
	glVertexPointer(3, GL_FLOAT, 0, &btVertices);
	glColorPointer(3, GL_FLOAT, 0, &btColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Back-bottom
	glVertexPointer(3, GL_FLOAT, 0, &bbVertices);
	glColorPointer(3, GL_FLOAT, 0, &bbColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Right-top face
	glVertexPointer(3, GL_FLOAT, 0, &rtVertices);
	glColorPointer(3, GL_FLOAT, 0, &rtColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Right-bottom
	glVertexPointer(3, GL_FLOAT, 0, &rbVertices);
	glColorPointer(3, GL_FLOAT, 0, &rbColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Left-top face
	glVertexPointer(3, GL_FLOAT, 0, &ltVertices);
	glColorPointer(3, GL_FLOAT, 0, &ltColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Left-bottom
	glVertexPointer(3, GL_FLOAT, 0, &lbVertices);
	glColorPointer(3, GL_FLOAT, 0, &lbColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Top-top face
	glVertexPointer(3, GL_FLOAT, 0, &ttVertices);
	glColorPointer(3, GL_FLOAT, 0, &ttColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Top-bottom
	glVertexPointer(3, GL_FLOAT, 0, &tbVertices);
	glColorPointer(3, GL_FLOAT, 0, &tbColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Bottom-top face
	glVertexPointer(3, GL_FLOAT, 0, &bbtVertices);
	glColorPointer(3, GL_FLOAT, 0, &bbtColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	// Bottom-bottom
	glVertexPointer(3, GL_FLOAT, 0, &bbbVertices);
	glColorPointer(3, GL_FLOAT, 0, &bbbColors);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

