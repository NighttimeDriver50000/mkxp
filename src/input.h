/*
** input.h
**
** This file is part of mkxp.
**
** Copyright (C) 2013 Jonas Kulla <Nyocurio@gmail.com>
**
** mkxp is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** mkxp is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with mkxp.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INPUT_H
#define INPUT_H

struct InputPrivate;
struct RGSSThreadData;

class Input
{
public:
	enum ButtonCode
	{
		None = 0,

		Down = 2, Left = 4, Right = 6, Up = 8,

		A = 11, B = 12, C = 13, D = 14,
		E = 15, F = 16, G = 17, H = 18,
		I = 19, J = 20, K = 21, L = 22,
		M = 23, N = 24, O = 25, P = 26,
		Q = 27, R = 28, S = 29, T = 30,
		U = 31, V = 32, W = 33, X = 34,
		Y = 35, Z = 36,

		Shift = 37, Ctrl = 38, Alt = 39,

		Escape = 40, Return = 41, Space = 42,

		F1 = 43, F2 = 44,  F3 = 45,  F4 = 46,
		F5 = 47, F6 = 48,  F7 = 49,  F8 = 50,
		F9 = 51, F10 = 52, F11 = 53, F12 = 54,

		// Non-standard extensions
		MouseLeft = 55, MouseMiddle = 56, MouseRight = 57
	};

	void update();

	bool isPressed(int button);
	bool isTriggered(int button);
	bool isRepeated(int button);

	int dir4Value();
	int dir8Value();

	/* Non-standard extensions */
	int mouseX();
	int mouseY();

private:
	Input(const RGSSThreadData &rtData);
	~Input();

	friend struct SharedStatePrivate;

	InputPrivate *p;
};

#endif // INPUT_H
