#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/pointing.h>
#include <dt-bindings/zmk/outputs.h>

#define ZMK_POINTING_DEFAULT_MOVE_VAL 1200  // default: 600
#define AS(keycode) &as LS(keycode) keycode
#define RAS(keycode) &as keycode LS(keycode)

/ { macros {	par: par 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LPAR &kp RPAR &kp LEFT>;			};
				brc: brc 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LBRC &kp RBRC &kp LEFT>; 			};
				bkt: bkt 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LBKT &kp RBKT &kp LEFT>; 			};
				quo: quo 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LS(APOS) &kp LS(APOS) &kp LEFT>; 	};
				gra: gra 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp GRAVE &kp GRAVE &kp LEFT>; 		};
				abt: abt 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LS(COMMA) &kp LS(DOT) &kp LEFT>; 	};
				bar: bar 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LS(BSLH) &kp LS(BSLH) &kp LEFT>; 	};
        	
				qu: qu 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp Q &kp U>; 							};
				ze: ze 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp Z &kp E>; 							};
				oa: oa 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp O &kp A>; 							};
				ue: ue 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp U &kp E>; 							}; };

	behaviors {
		hml: home_row_mod_l { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; require-prior-idle-ms = <200>; 
   			tapping-term-ms = <275>; quick-tap-ms = <175>; hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; hold-trigger-on-release; 			};
        hmr: home_row_mod_r { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; require-prior-idle-ms = <200>;
			tapping-term-ms = <200>; quick-tap-ms = <175>; hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; hold-trigger-on-release; 			};
		sl { 							release-after-ms = < 1500 >; 																					};
        num_word: num_word { 			#binding-cells = <1>; compatible = "zmk,behavior-auto-layer"; 
										continue-list = < BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL >; ignore-numbers;								};
		amt: a_mod_tap { 				compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
										tapping-term-ms = <200>; bindings = <&kp>, <&kp>; display-name = "a-Mod-Tap"; 									};
		mage_rep: mage_rep { 			compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&key_repeat>;
											akt_yi { trigger-keys = <Y>; max-prior-idle-ms = <300>; bindings = <&kp I>; };
            								akt_ji { trigger-keys = <J>; max-prior-idle-ms = <300>; bindings = <&kp I>; }; 								};
		mage_k: mage_k { 				compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp K>;
											akt_tw { trigger-keys = <T>; max-prior-idle-ms = <300>; bindings = <&kp W>; };
											akt_gs { trigger-keys = <G>; max-prior-idle-ms = <300>; bindings = <&kp S>; }; 								};
		mage_j: mage_j { 				compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp J>;
											akt_ue { trigger-keys = <U>; max-prior-idle-ms = <300>; bindings = <&kp E>; }; 								};
		cmt: caps_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; tapping-term-ms = <200>; 
			bindings = <&kp>, <&caps_word>; display-name = "Caps-Tap"; 																					};
		sk: sticky_key { release-after-ms = <750>; quick-release; lazy; /delete-property/ ignore-modifiers; 											};
		mt: mod_tap { tapping-term-ms = <200>; 																											};
		quomt: quo_mod_tap { compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>; 
			bindings = <&quo>, <&kp>; display-name = "quo Mod-Tap"; 																					};
		parmt: par_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&gra>, <&par>; display-name = "par Mod-Tap"; 																					};
		brcmt: brc_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
			bindings = <&abt>, <&brc>; display-name = "brc Mod-Tap"; 																					};
		bktmt: bkt_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&bar>, <&bkt>; display-name = "bkt Mod-Tap"; 																					};
		gramt: gra_mod_tap { compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&gra>, <&kp>; display-name = "gra Mod-Tap"; 																					};
		abtmt: abt_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&abt>, <&kp>; display-name = "abt Mod-Tap"; 																					};
		barmt: bar_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>; 
			bindings = <&bar>, <&kp>; display-name = "bar Mod-Tap"; 																					};
		qumt: qu_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&kp>, <&qu>; display-name = "qu Mod-Tap"; 																						};
		zemt: ze_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&kp>, <&ze>; display-name = "ze Mod-Tap"; 																						};
		oamt: oa_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&oa>, <&kp>; display-name = "oa Mod-Tap"; 																						};
		uemt: ue_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&ue>, <&kp>;  display-name = "ue Mod-Tap"; 																						}; }; };


//
// t0  t1  t2  t3  t4  t5  t6  t7  t8  t9  t10  t11
// h0 *h1**h2**h3**h4* h5  h6 *h7**h8**h9**h10* h11
// b0  b1  b2  b3  b4  b5  b6  b7  b8  b9  b10  b11
//             th0 *th1* th2  th3 *th4* th5
//

// layer 0 - base
	// left hand
		// top row
			#define t0 		&kp TAB
			#define t1 		&kp V
			#define t2 		&kp Y
			#define t3 		&kp O
			#define t4 		&kp U
			#define t5 		&zemt Z 0
		// home row
			#define h0 		&amt LC(DEL) DEL
			#define h1 		&hml LSHIFT C
			#define h2 		&hml LALT I
			#define h3 		&hml LGUI A
			#define h4 		&hml LCTRL E
			#define h5 		&qumt Q 0
		// bottom row
			#define b0 		&amt LC(BSPC) BSPC
			#define b1 		&kp LSHIFT
			#define b2 		&mage_j
			#define b3 		&kp X
			#define b4 		&mage_rep
			#define b5 		&none
	
	// right hand
		// top row
			#define u6 		&kp P
			#define u7 		&kp D
			#define u8 		&kp L
			#define u9 		&kp F
			#define u10 	&kp B
			#define u11 	&kp ESC
		// home row
			#define h6 		&kp W
			#define h7 		&hmr RCTRL T
			#define h8 		&hmr RGUI H
			#define h9 		&hmr RALT S
			#define h10		&hmr RSHIFT N
			#define h11		&amt RC(BSPC) BSPC
		// bottom row
			#define b6 		&none
			#define b7 		&mage_k
			#define b8 		&kp M
			#define b9 		&kp G
			#define b10		&kp RSHIFT
			#define b11		&amt RC(DEL) DEL

	// thumbfan
		// 
			#define th0 		&none
			#define th1 		&lt 1 R
			#define th2		&none
			
			#define th3 		&none
			#define	th4		&lt 2 SPACE
			#define th5		&none

// layer 1 - numbers and icons
	// left hand
		// top row
			#define LUO1 &none
			#define LUP1 AS(GRAVE)
			#define LUR1 AS(N1)
			#define LUM1 AS(N2)
			#define LUI1 AS(N3)
			#define LUN1 &none
		// home row
			#define LHO1 &none
			#define LHP1 AS(N0)
			#define LHR1 AS(N4)
			#define LHM1 AS(N5)
			#define LHI1 AS(N6)
			#define LHN1 &none
		// bottom row
			#define LBO1 &none
			#define LBP1 &none
			#define LBR1 &none
			#define LBM1 AS(N7)
			#define LBI1 AS(N8)
			#define LBN1 &none
	
	// right hand
		// top row
			#define RUO1 &none
			#define RUP1 AS(GRAVE)
			#define RUR1 &td2
			#define RUM1 &td1
			#define RUI1 &td0
			#define RUN1 AS(GRAVE)
		// home row
			#define RHO1 &none
			#define RHP1 AS(FSLH)
			#define RHR1 AS(DOT)
			#define RHM1 AS(COMMA)
			#define RHI1 AS(SEMI)
			#define RHN1 AS(EQUAL)
		// bottom row
			#define RBO1 &none
			#define RBP1 AS(BSLH)
			#define RBR1 AS(EQUAL)
			#define RBM1 AS(MINUS)
			#define RBI1 AS(APOS)
			#define RBN1 AS(BSLH)

	// thumbfan
		// 2 keys
			#define L1 AS(N9)
			#define R1 &none
		// 4 keys
			#define LN1 &none
			#define LH1 AS(N9)

			#define	RH1 &none
			#define RN1 &none

// layer 2 - nav/kb functions
	// left hand
		// top row
			#define LUO2 &none
			#define LUP2 &none
			#define LUR2 &studio_unlock
			#define LUM2 &bt BT_CLR_ALL
			#define LUI2 &hw_soft_off
			#define LUN2 &none
		// home row
			#define LHO2 &none
			#define LHP2 &none
			#define LHR2 &kp HOME
			#define LHM2 &kp PGUP 
			#define LHI2 &kp END
			#define LHN2 &none
		// bottom row
			#define LBO2 &none
			#define LBP2 &none
			#define LBR2 &none
			#define LBM2 &kp PGDN
			#define LBI2 &bootloader
			#define LBN2 &none
	
	// right hand
		// top row
			#define RUO2 &none
			#define RUP2 &none
			#define RUR2 &kp C_NEXT
			#define RUM2 &kp C_PP
			#define RUI2 &kp C_PREV
			#define RUN2 &none
		// home row
			#define RHO2 &none
			#define RHP2 &none
			#define RHR2 &kp RIGHT
			#define RHM2 &kp UP
			#define RHI2 &kp LEFT
			#define RHN2 &none
		// bottom row
			#define RBO2 &none
			#define RBP2 &none
			#define RBR2 &none
			#define RBM2 &kp DOWN
			#define RBI2 &none
			#define RBN2 &none

	// thumbfan
		// 2 keys
			#define L2 &none
			#define R2 &none
		// 4 keys
			#define LN2 &none
			#define LH2 &none

			#define	RH2 &none
			#define RN2 &none

