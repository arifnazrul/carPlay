//
//  JDServices.h
//  NSMutableString+JDObfuscation.h
//
//  Created by Bott Sebastian on 2016-02-12
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@import Foundation;

#define JDObfuscate [NSMutableString string]


/**
 * @brief String obfuscation.\n
 * Protects sensitive strings in the compiled binary.
 */
@interface NSMutableString (JDObfuscation)

#pragma mark lowercase
- (instancetype _Nonnull)_a;
- (instancetype _Nonnull)_b;
- (instancetype _Nonnull)_c;
- (instancetype _Nonnull)_d;
- (instancetype _Nonnull)_e;
- (instancetype _Nonnull)_f;
- (instancetype _Nonnull)_g;
- (instancetype _Nonnull)_h;
- (instancetype _Nonnull)_i;
- (instancetype _Nonnull)_j;
- (instancetype _Nonnull)_k;
- (instancetype _Nonnull)_l;
- (instancetype _Nonnull)_m;
- (instancetype _Nonnull)_n;
- (instancetype _Nonnull)_o;
- (instancetype _Nonnull)_p;
- (instancetype _Nonnull)_q;
- (instancetype _Nonnull)_r;
- (instancetype _Nonnull)_s;
- (instancetype _Nonnull)_t;
- (instancetype _Nonnull)_u;
- (instancetype _Nonnull)_v;
- (instancetype _Nonnull)_w;
- (instancetype _Nonnull)_x;
- (instancetype _Nonnull)_y;
- (instancetype _Nonnull)_z;
- (instancetype _Nonnull)_ä;
- (instancetype _Nonnull)_ö;
- (instancetype _Nonnull)_ü;
- (instancetype _Nonnull)_ß;

#pragma mark UPPERCASE
- (instancetype _Nonnull)_A;
- (instancetype _Nonnull)_B;
- (instancetype _Nonnull)_C;
- (instancetype _Nonnull)_D;
- (instancetype _Nonnull)_E;
- (instancetype _Nonnull)_F;
- (instancetype _Nonnull)_G;
- (instancetype _Nonnull)_H;
- (instancetype _Nonnull)_I;
- (instancetype _Nonnull)_J;
- (instancetype _Nonnull)_K;
- (instancetype _Nonnull)_L;
- (instancetype _Nonnull)_M;
- (instancetype _Nonnull)_N;
- (instancetype _Nonnull)_O;
- (instancetype _Nonnull)_P;
- (instancetype _Nonnull)_Q;
- (instancetype _Nonnull)_R;
- (instancetype _Nonnull)_S;
- (instancetype _Nonnull)_T;
- (instancetype _Nonnull)_U;
- (instancetype _Nonnull)_V;
- (instancetype _Nonnull)_W;
- (instancetype _Nonnull)_X;
- (instancetype _Nonnull)_Y;
- (instancetype _Nonnull)_Z;
- (instancetype _Nonnull)_Ä;
- (instancetype _Nonnull)_Ö;
- (instancetype _Nonnull)_Ü;

#pragma mark Numbers
- (instancetype _Nonnull)_0;
- (instancetype _Nonnull)_1;
- (instancetype _Nonnull)_2;
- (instancetype _Nonnull)_3;
- (instancetype _Nonnull)_4;
- (instancetype _Nonnull)_5;
- (instancetype _Nonnull)_6;
- (instancetype _Nonnull)_7;
- (instancetype _Nonnull)_8;
- (instancetype _Nonnull)_9;

#pragma mark Punctuation
- (_Nonnull instancetype)_space;
- (_Nonnull instancetype)_dot;
- (_Nonnull instancetype)_colon;
- (_Nonnull instancetype)_semicolon;
- (_Nonnull instancetype)_comma;
- (_Nonnull instancetype)_dash;
- (_Nonnull instancetype)_underscore;
- (_Nonnull instancetype)_hash;
- (_Nonnull instancetype)_apostrophe;
- (_Nonnull instancetype)_plus;
- (_Nonnull instancetype)_asterisk;
- (_Nonnull instancetype)_lessThan;
- (_Nonnull instancetype)_greaterThan;
- (_Nonnull instancetype)_caret;
- (_Nonnull instancetype)_degree;
- (_Nonnull instancetype)_exclamationMark;
- (_Nonnull instancetype)_quotationMark;
- (_Nonnull instancetype)_section;
- (_Nonnull instancetype)_dollar;
- (_Nonnull instancetype)_percent;
- (_Nonnull instancetype)_ampersand;
- (_Nonnull instancetype)_slash;
- (_Nonnull instancetype)_backslash;
- (_Nonnull instancetype)_bracketOpen;
- (_Nonnull instancetype)_bracketClose;
- (_Nonnull instancetype)_curlyBracketOpen;
- (_Nonnull instancetype)_curlyBracketClose;
- (_Nonnull instancetype)_squareBracketOpen;
- (_Nonnull instancetype)_squareBracketClose;
- (_Nonnull instancetype)_questionMark;
- (_Nonnull instancetype)_equals;
- (_Nonnull instancetype)_at;
- (_Nonnull instancetype)_pipe;
- (_Nonnull instancetype)_tilde;

@end
