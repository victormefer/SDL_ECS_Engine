#ifndef LEVELEDITORSTATE_HPP
#define LEVELEDITORSTATE_HPP

#include "State.hpp"
#include "StateMachine.hpp"
#include "StateEventEnum.hpp"
#include "FirstLevelEditor.hpp"
#include "Panel.hpp"
#include "TileSet.hpp"
#include "TileMap.hpp"
#include "TilesPanel.hpp"

class LevelEditorState: public State
{
public:
	LevelEditorState();
	~LevelEditorState();
	void create(StateMachine& stateMachine);
	void initGUI();
	void update(float dt);
	void render();
	void handle(StateEventEnum& event);
private:
	Rect getPanelRect(Rect& parent, Rect& proportions);

	TileSet* tileSet_;
	TileMap* tileMap_;
	Panel mainPanel_;

	std::vector<Button*> tileButtons_;

	int selectedTile;
};

void tileBtnExecute(State* state);

#endif