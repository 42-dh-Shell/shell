/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:32:45 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/27 14:14:23 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_TABLE_H
# define CHAR_TABLE_H

# define WORD 0
# define NOT_WORD 1
# define IS_SPACE 2
# define DOUBLE_QUOTE 3
# define EXPANSION 4
# define BIT_AND 5
# define SINGLE_QUOTE 6
# define BIT_OR 7
# define LEFT_BRAKIT 8
# define RIGHT_BRAKIT 9
# define LEFT_ARROW 10
# define RIGHT_ARROW 11
# define WILD_CARD 12

static const char	g_char_table[256] = {
	NOT_WORD, // 0 
	NOT_WORD, // 1
	NOT_WORD,	//2
	NOT_WORD, // 3
	NOT_WORD, //4 
	NOT_WORD, //5 
	NOT_WORD, //6 
	NOT_WORD, //7 
	NOT_WORD, //8 
	IS_SPACE, //9 
	IS_SPACE, //10 
	IS_SPACE, //11 
	IS_SPACE, //12 
	IS_SPACE, //13 
	NOT_WORD, //14 
	NOT_WORD, //15 
	NOT_WORD, //16 
	NOT_WORD, //17 
	NOT_WORD, //18 
	NOT_WORD, //19 
	NOT_WORD, //20 
	NOT_WORD, //21 
	NOT_WORD, //22 
	NOT_WORD, //23 
	NOT_WORD, //24 
	NOT_WORD, //25 
	NOT_WORD, //26 
	NOT_WORD, //27 
	NOT_WORD, //28 
	NOT_WORD, //29 
	NOT_WORD, //30 
	NOT_WORD, //31 
	IS_SPACE, //32 
	WORD, //33
	DOUBLE_QUOTE, //34
	WORD, //35
	EXPANSION, //36
	WORD, //37
	BIT_AND, //38 &
	SINGLE_QUOTE, //39
	LEFT_BRAKIT, //40
	RIGHT_BRAKIT, //41
	WILD_CARD, //42
	WORD, //43
	WORD, //44
	WORD, //45
	WORD, //46
	WORD, //47
	WORD, //48
	WORD, //49
	WORD, //50
	WORD, //51
	WORD, //52
	WORD, //53
	WORD, //54
	WORD, //55
	WORD, //56
	WORD, //57
	WORD, //58
	WORD, //59
	LEFT_ARROW, //60
	WORD, //61
	RIGHT_ARROW, //62
	WORD, //63
	WORD, //64
	WORD, //65
	WORD, //66
	WORD, //67
	WORD, //68
	WORD, //69
	WORD, //70
	WORD, //71
	WORD, //72
	WORD, //73
	WORD, //74
	WORD, //75
	WORD, //76
	WORD, //77
	WORD, //78
	WORD, //79
	WORD, //80
	WORD, //81
	WORD, //82
	WORD, //83
	WORD, //84
	WORD, //85
	WORD, //86
	WORD, //87
	WORD, //88
	WORD, //89
	WORD, //90
	WORD, //91
	WORD, //92
	WORD, //93
	WORD, //94
	WORD, //95
	WORD, //96
	WORD, //97
	WORD, //98
	WORD, //99
	WORD, //100
	WORD, //101
	WORD, //102
	WORD, //103
	WORD, //104
	WORD, //105
	WORD, //106
	WORD, //107
	WORD, //108
	WORD, //109
	WORD, //110
	WORD, //111
	WORD, //112
	WORD, //113
	WORD, //114
	WORD, //115
	WORD, //116
	WORD, //117
	WORD, //118
	WORD, //119
	WORD, //120
	WORD, //121
	WORD, //122
	WORD, //123
	BIT_OR, //124 |
	WORD, //125
	WORD, //126
	NOT_WORD, //127 
	WORD,				// 128 //
	WORD,				// 129 //
	WORD,				// 130 //
	WORD,				// 131 //
	WORD,				// 132 //
	WORD,				// 133 //
	WORD,				// 134 //
	WORD,				// 135 //
	WORD,				// 136 //
	WORD,				// 137 //
	WORD,				// 138 //
	WORD,				// 139 //
	WORD,				// 140 //
	WORD,				// 141 //
	WORD,				// 142 //
	WORD,				// 143 //
	WORD,				// 144 //
	WORD,				// 145 //
	WORD,				// 146 //
	WORD,				// 147 //
	WORD,				// 148 //
	WORD,				// 149 //
	WORD,				// 150 //
	WORD,				// 151 //
	WORD,				// 152 //
	WORD,				// 153 //
	WORD,				// 154 //
	WORD,				// 155 //
	WORD,				// 156 //
	WORD,				// 157 //
	WORD,				// 158 //
	WORD,				// 159 //
	WORD,				// 160 //
	WORD,				// 161 //
	WORD,				// 162 //
	WORD,				// 163 //
	WORD,				// 164 //
	WORD,				// 165 //
	WORD,				// 166 //
	WORD,				// 167 //
	WORD,				// 168 //
	WORD,				// 169 //
	WORD,				// 170 //
	WORD,				// 171 //
	WORD,				// 172 //
	WORD,				// 173 //
	WORD,				// 174 //
	WORD,				// 175 //
	WORD,				// 176 //
	WORD,				// 177 //
	WORD,				// 178 //
	WORD,				// 179 //
	WORD,				// 180 //
	WORD,				// 181 //
	WORD,				// 182 //
	WORD,				// 183 //
	WORD,				// 184 //
	WORD,				// 185 //
	WORD,				// 186 //
	WORD,				// 187 //
	WORD,				// 188 //
	WORD,				// 189 //
	WORD,				// 190 //
	WORD,				// 191 //
	WORD,				// 192 //
	WORD,				// 193 //
	WORD,				// 194 //
	WORD,				// 195 //
	WORD,				// 196 //
	WORD,				// 197 //
	WORD,				// 198 //
	WORD,				// 199 //
	WORD,				// 200 //
	WORD,				// 201 //
	WORD,				// 202 //
	WORD,				// 203 //
	WORD,				// 204 //
	WORD,				// 205 //
	WORD,				// 206 //
	WORD,				// 207 //
	WORD,				// 208 //
	WORD,				// 209 //
	WORD,				// 210 //
	WORD,				// 211 //
	WORD,				// 212 //
	WORD,				// 213 //
	WORD,				// 214 //
	WORD,				// 215 //
	WORD,				// 216 //
	WORD,				// 217 //
	WORD,				// 218 //
	WORD,				// 219 //
	WORD,				// 220 //
	WORD,				// 221 //
	WORD,				// 222 //
	WORD,				// 223 //
	WORD,				// 224 //
	WORD,				// 225 //
	WORD,				// 226 //
	WORD,				// 227 //
	WORD,				// 228 //
	WORD,				// 229 //
	WORD,				// 230 //
	WORD,				// 231 //
	WORD,				// 232 //
	WORD,				// 233 //
	WORD,				// 234 //
	WORD,				// 235 //
	WORD,				// 236 //
	WORD,				// 237 //
	WORD,				// 238 //
	WORD,				// 239 //
	WORD,				// 240 //
	WORD,				// 241 //
	WORD,				// 242 //
	WORD,				// 243 //
	WORD,				// 244 //
	WORD,				// 245 //
	WORD,				// 246 //
	WORD,				// 247 //
	WORD,				// 248 //
	WORD,				// 249 //
	WORD,				// 250 //
	WORD,				// 251 //
	WORD,				// 252 //
	WORD,				// 253 //
	WORD,				// 254 //
	WORD,				// 255 //
};

#endif