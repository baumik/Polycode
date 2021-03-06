/*
Copyright (C) 2011 by Ivan Safrin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


#pragma once
#include "PolyGlobals.h"
#include "PolyScreenEntity.h"
#include "PolyObject.h"
#include "PolyScreenShape.h"
#include "PolyScreenImage.h"
#include "PolyScreenLabel.h"
#include "PolyScreenSound.h"
#include "PolyScreenSprite.h"
#include "PolyParticleEmitter.h"
#include "PolyParticle.h"
#include "PolySound.h"

namespace Polycode {

class ScreenEntityInstance : public ScreenEntity {
	public:
		ScreenEntityInstance(const String& fileName);
		~ScreenEntityInstance();
		
		void parseObjectIntoCurve(ObjectEntry *entry, BezierCurve *curve);
		void applyScreenShape(ObjectEntry *entry, ScreenShape *shape);
		ScreenEntity *loadObjectEntryIntoEntity(ObjectEntry *entry);
		bool loadFromFile(const String& fileName);
		
		ScreenEntity *getRootEntity();
		
		String getFileName() const;
		
	protected:
		ScreenEntity *rootEntity;		
		String fileName;
};

}