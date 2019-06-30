#include "CharacterKeyboardInput.hpp"
#include <RTTI/RTTI_CharacterKeyboardInput.hpp>
#include <components/CharacterAI.hpp>
#include <exception/Throw.hpp>

namespace REGoth
{
  CharacterKeyboardInput::CharacterKeyboardInput(const bs::HSceneObject& parent)
      : bs::Component(parent)
  {
    setName("CharacterKeyboardInput");

    // Inside constructor so this doesn't run after deserialization where
    // we already have the reference
    mCharacterAI = SO()->getComponent<CharacterAI>();

    if (mCharacterAI.isDestroyed())
    {
      REGOTH_THROW(InvalidStateException,
                   bs::StringUtil::format("Scene Object {0} does not have a CharacterAI component!",
                                          SO()->getName()));
    }
  }

  CharacterKeyboardInput::~CharacterKeyboardInput()
  {
  }

  void CharacterKeyboardInput::onInitialized()
  {
    bs::Component::onInitialized();

    mMoveForward = bs::VirtualButton("Forward");
    mMoveBack    = bs::VirtualButton("Back");
    mMoveLeft    = bs::VirtualButton("Left");
    mMoveRight   = bs::VirtualButton("Right");
    mFastMove    = bs::VirtualButton("FastMove");
    mAction      = bs::VirtualButton("Action");
  }

  void CharacterKeyboardInput::fixedUpdate()
  {
    bool goingForward = bs::gVirtualInput().isButtonHeld(mMoveForward);
    bool goingBack    = bs::gVirtualInput().isButtonHeld(mMoveBack);
    bool goingLeft    = bs::gVirtualInput().isButtonHeld(mMoveLeft);
    bool goingRight   = bs::gVirtualInput().isButtonHeld(mMoveRight);
    bool fastMove     = bs::gVirtualInput().isButtonHeld(mFastMove);

    bool action = bs::gVirtualInput().isButtonDown(mAction);

    if (action)
    {
      mCharacterAI->doAction();
    }

    // Always keep the user controllers physics active
    mCharacterAI->activatePhysics();

    if (goingForward)
    {
      mCharacterAI->goForward();
    }
    else if (goingBack)
    {
      mCharacterAI->goBackward();
    }
    else
    {
      mCharacterAI->stopMoving();
    }

    if (goingLeft)
    {
      mCharacterAI->turnLeft();
    }
    else if (goingRight)
    {
      mCharacterAI->turnRight();
    }
    else
    {
      mCharacterAI->stopTurning();
    }

    if (fastMove)
    {
      mCharacterAI->fastMove(4.0f);
    }
    else
    {
      mCharacterAI->fastMove(1.0f);
    }
  }

  REGOTH_DEFINE_RTTI(CharacterKeyboardInput)
}  // namespace REGoth
