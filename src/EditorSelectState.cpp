#include "../include/EditorSelectState.hpp"
#include "../include/InputHandler.hpp"
#include "../include/Resources.hpp"

EditorSelectState::EditorSelectState() : 
	bg_("../img/bg.png"), 
	mode(INIT),
	btnNewMap("../img/interface/editor/btn_1.png"),
	btnNewMapPos(300, 250, 200, 100),
	btnNewMapText("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Novo mapa", Colors::black),
	btnEditMap("../img/interface/editor/btn_1.png"),
	btnEditMapPos(600, 250, 200, 100),
	btnEditMapText("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Editar mapa", Colors::black),
	btnAccept("../img/interface/editor/btn_1.png"),
	btnAcceptPos(900, 500, 100, 60),
	btnAcceptText("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Proximo", Colors::black),
	btnReturn("../img/interface/editor/btn_1.png"),
	btnReturnPos(750, 500, 100, 60),
	btnReturnText("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Voltar", Colors::black),
	textLabels(),
	textAreas(),
	selectedTextArea(0)
{
	btnNewMapText.setPos(400, 300);
	btnEditMapText.setPos(700, 300);

	btnAcceptText.setPos(950, 515);
	btnReturnText.setPos(800, 515);

	btnNewMap.setScaleX(200 / btnNewMap.getWidth());
	btnNewMap.setScaleY(100 / btnNewMap.getHeight());
	btnEditMap.setScaleX(200 / btnEditMap.getWidth());
	btnEditMap.setScaleY(100 / btnEditMap.getHeight());

	btnAccept.setScaleX(100 / btnAccept.getWidth());
	btnAccept.setScaleY(60 / btnAccept.getHeight());
	btnReturn.setScaleX(100 / btnReturn.getWidth());
	btnReturn.setScaleY(60 / btnReturn.getHeight());
}

EditorSelectState::~EditorSelectState()
{
	textLabels.clear();
	textAreas.clear();
}


void EditorSelectState::update(float dt)
{
	InputHandler& input = InputHandler::getInstance();
	input.update();

	if (mode == INIT)
	{
		if (input.mousePress(LEFT_MOUSE_BUTTON))
		{
			if (btnNewMapPos.isInside(input.getMouse()))
			{
				mode = NEW_MAP;
				selectedTextArea = 0;
				textAreas.clear();
				textLabels.clear();

				textLabels.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Nome:", Colors::black));
				textLabels[0]->setPos(200, 150, false, false);
				textAreas.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Fase", Colors::blue));
				textAreas[0]->setPos(400, 150, false, false);

				textLabels.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Largura:", Colors::black));
				textLabels[1]->setPos(200, 250, false, false);
				textAreas.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "50", Colors::black));
				textAreas[1]->setPos(400, 250, false, false);

				textLabels.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Altura:", Colors::black));
				textLabels[2]->setPos(200, 350, false, false);
				textAreas.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "30", Colors::black));
				textAreas[2]->setPos(400, 350, false, false);
			}
			else if (btnEditMapPos.isInside(input.getMouse()))
			{
				mode = EDIT_MAP;
				selectedTextArea = 0;
				textAreas.clear();
				textLabels.clear();

				textLabels.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Imagem tile set:", Colors::black));
				textLabels[0]->setPos(200, 150, false, false);
				textAreas.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "../img/maps/tile_set.png", Colors::blue));
				textAreas[0]->setPos(400, 150, false, false);

				textLabels.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Tile map:", Colors::black));
				textLabels[1]->setPos(200, 250, false, false);
				textAreas.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "../map/tileMap.txt", Colors::black));
				textAreas[1]->setPos(400, 250, false, false);

				textLabels.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Collision map:", Colors::black));
				textLabels[2]->setPos(200, 350, false, false);
				textAreas.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "../map/collisionMap.txt", Colors::black));
				textAreas[2]->setPos(400, 350, false, false);

				textLabels.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "Object map:", Colors::black));
				textLabels[3]->setPos(200, 450, false, false);
				textAreas.emplace_back(new Text("../font/arial.ttf", 16, Text::TextStyle::BLENDED, "../map/objectMap.xml", Colors::black));
				textAreas[3]->setPos(400, 450, false, false);

			}
		}
	}
	else
	{
		if (input.mousePress(LEFT_MOUSE_BUTTON))
		{
			if (btnAcceptPos.isInside(input.getMouse()))
			{
				accept();
			}
			else if (btnReturnPos.isInside(input.getMouse()))
			{
				mode = INIT;
			}
			else
			{
				for (int i = 0; i < (int)textAreas.size(); i++)
				{
					if (textAreas[i]->getPos().isInside(input.getMouse()))
					{
						textAreas[selectedTextArea]->setColor(Colors::black);
						textAreas[i]->setColor(Colors::blue);
						selectedTextArea = i;
						break;
					}
				}
			}
		}

		if (input.textInput())
			textAreas[selectedTextArea]->setText( textAreas[selectedTextArea]->getText() + input.getText() );
		if (input.keyPress(BACKSPACE))
		{
			std::string newText = textAreas[selectedTextArea]->getText();
			newText.pop_back();
			textAreas[selectedTextArea]->setText( newText );
		}

	}

	if (input.quitRequested()) {
		quit_ = true;
	}
}


void EditorSelectState::render()
{
	bg_.render(0,0);

	if (mode == INIT)
	{
		// NEW MAP BTN
		btnNewMap.render(btnNewMapPos.x(), btnNewMapPos.y());
		btnNewMapText.render();

		// EDIT MAP BTN
		btnEditMap.render(btnEditMapPos.x(), btnEditMapPos.y());
		btnEditMapText.render();
	}
	else
	{
		for (int i = 0; i < (int)textLabels.size(); i++)
		{
			textLabels[i]->render();
			textAreas[i]->render();
		}

		btnAccept.render(btnAcceptPos.x(), btnAcceptPos.y());
		btnAcceptText.render();
		btnReturn.render(btnReturnPos.x(), btnReturnPos.y());
		btnReturnText.render();
	}
}


void EditorSelectState::accept()
{
	// check info
}



void EditorSelectState::pause()
{

}

void EditorSelectState::resume()
{

}