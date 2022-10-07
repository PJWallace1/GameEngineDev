/*
void moveLeft(int numPix, Player p) {
	Playertemp = p;
	temp.setXPos(p.getXPos + numPix);
	if (!PhysicsEngine.isCollison(temp)) {
		p.setXPos(p.getXPos + numPix);
	}
}
void moveRight(int numPix, Obj myObj) {
	Playertemp = p;
	temp.setXPos(p.getXPos - numPix);
	if (!PhysicsEngine.isCollison(temp)) {
		p.setXPos(p.getXPos - numPix);
	}
}
void jump(int numPix, Player p) {
	Playertemp = p;
	temp.setYPos(p.getYPos - numPix);
	if (!PhysicsEngine.isCollison(temp)) {
		p.setYPos(p.getYPos - numPix);
	}
}
shoot(Gun g, Player p, int mouseX, int mouseY) {
	//Check that gun can shoot
	//Create bullet(s)
	//Apply trajectory
	//Apply speed
	//Add to appropriate arrays
	//Subtract from gun ammo count
}
crouch(Player p) {
	p.isCrouched = true;
}
reload(Gun g) {
	g.reload();
}
interact(Player p) {
	//Make sure the player can interact
	//Detect if any intercactable objects are nearby
	//Break any ties
	//Apply interaction effects
}
discardItem(Player p) {
	if (p.getPrimaryItem() != NULL) {
		p.setPrimaryItem(NULL);
		Particle d = new Particle("destroyedObj.spr", p.getXPos, p.getYPos);
		PhysicsEngine.addCollisionObj(d);
		PhysicsEngine.addVisibleObj(d);
		PhysicsEngine.addDestroyableObj(d);
	}
}
accessInventory() {
	//Change gamemode
	//Generate Inventory GUI
	//Add items to inventory GUI
}
switchItem(Player p) {
	Item temp = p.getPrimaryItem();
	p.setPrimaryItem(p.getSecondaryItem());
	p.setSecondaryItem(p.getPrimaryItem());
}
activateAbility() {
	//Identify what ability the player has
	//Check to make sure ability can be activated
	//Apply ability effects
}
useItem(Player p) {
	//Check player has item
	//Confirm item can be used
	//Apply item effects	
}
meleeAttack(Player p) {
	if (p.attackTimer == 0) {
		Hitbox m = new Hitbox(p.getAttackCoords(), p.getAttackWidth(), p.getAttackHeight());
		PhysicsEngine.addCollisionObj(m);
		PhysicsEngine.addDestroyableObj(m);
		//Add to visible?
	}
}
Escape() {
	//Change gamemode
	//Create pause gui
}
*/