#define AS(keycode) &as LS(keycode) keycode

/ {
	macros {
        	qu: qu {
            		compatible = "zmk,behavior-macro";
            		#binding-cells = <0>;
            		bindings
                	= <&macro_tap &kp Q &kp U>
                	;
        	};
		lol: lol {
            		compatible = "zmk,behavior-macro";
            		#binding-cells = <0>;
            		bindings
                	= <&macro_tap &kp L &kp O &kp L>
                	;
        	};
		lmao: lmao {
            		compatible = "zmk,behavior-macro";
            		#binding-cells = <0>;
            		bindings
                	= <&macro_tap &kp L &kp M &kp A &kp O>
                	;
        	};
    	};
	behaviors {
		td0: tap_dance_parentheseseseses {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp LPAR>, <&kp RPAR>;
		};
		td1: tap_dance_braces {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp LBRC>,<&kp RBRC>;
		};
		td2: tap_dance_brackets {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp LBKT>,<&kp RBKT>;
		};
		td3: tap_dance_tabesc {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp TAB>,<&kp ESC>;
		};
		td4: tap_dance_cx {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp C>,<&kp X>;
		};
		td5: tap_dance_fg {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp F>,<&kp G>;
		};
		hml: home_row_mod_left {
            		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		flavor = "balanced";
            		require-prior-idle-ms = <100>;
            		tapping-term-ms = <250>;
            		quick-tap-ms = <175>;
            		bindings = <&kp>, <&kp>;
            		hold-trigger-key-positions = <3 4 5 10 11 12 13 16 17 19>; // List of keys on the right
            		hold-trigger-on-release;
        	};
        	hmr: home_row_mod_right {
            		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		flavor = "balanced";
            		require-prior-idle-ms = <100>;
            		tapping-term-ms = <250>;
            		quick-tap-ms = <175>;
            		bindings = <&kp>, <&kp>;
            		hold-trigger-key-positions = <0 1 2 6 7 8 9 14 15 18>; // List of keys on the left
            		hold-trigger-on-release;
        	};
		as: auto_shift {
            		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		tapping_term_ms = <175>;
            		quick_tap_ms = <0>;
            		flavor = "tap-preferred";
            		bindings = <&kp>, <&kp>;
        	};
		hw_soft_off: hw_soft_off {
            		compatible = "zmk,behavior-soft-off";
            		#binding-cells = <0>;
            		split-peripheral-off-on-press; // Turn peripheral off immediately for reliability
            		hold-time-ms = <1500>; // Only turn off if the key is held for 1.5 seconds or longer.
        	};
		fmt: fast_mod_tap {
        		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		flavor = "hold-preferred";
            		tapping-term-ms = <125>;
            		bindings = <&kp>, <&kp>;
            		display-name = "Fast Mod-Tap";
        	};
		mt: mod_tap {
            		tapping-term-ms = <200>;
        	};
	};


// layer 0
	// left hand
		// top row
			#define LUO &kp TAB
			#define LUP &none
			#define LUR &kp U
			#define LUM &kp O
			#define LUI &kp G
			#define LUN &kp J
		// home row
			#define LHO &kp DEL
			#define LHP &hml LSHIFT A
			#define LHR &kp I
			#define LHM &hml LALT E
			#define LHI &hml LCTRL T
			#define LHN &kp K
		// bottom row
			#define LBO &none
			#define LBP &none
			#define LBR &none
			#define LBM &kp X
			#define LBI &kp B
			#define LBN &kp Z
	
	// right hand
		// top row
			#define RUO &none
			#define RUP &qu
			#define RUR &kp C
			#define RUM &kp Y
			#define RUI &kp M
			#define RUN &kp F
		// home row
			#define RHO &kp BACK
			#define RHP &hmr RSHIFT H
			#define RHR &kp D
			#define RHM &hmr LALT S
			#define RHI &hmr RCTRL N
			#define RHN &kp P
		// bottom row
			#define RBO &none
			#define RBP &none
			#define RBR &none
			#define RBM &kp W
			#define RBI &kp L
			#define RBN &kp V

	// thumbfan
		// 2 keys
			#define L &lt 2 R
			#define R &lt 1 SPACE
		// 4 keys
			#define LN &lt 3 J
			#define LH &lt 2 R

			#define	RH &lt 1 SPACE
			#define RN &lt 4 Z

// layer 1
	// left hand
		// top row
			#define LUO1
			#define LUP1
			#define LUR1
			#define LUM1
			#define LUI1
			#define LUN1
		// home row
			#define LHO1
			#define LHP1
			#define LHR1
			#define LHM1
			#define LHI1
			#define LHN1
		// bottom row
			#define LBO1
			#define LBP1
			#define LBR1
			#define LBM1
			#define LBI1
			#define LBN1
	
	// right hand
		// top row
			#define RUO1
			#define RUP1
			#define RUR1
			#define RUM1
			#define RUI1
			#define RUN1
		// home row
			#define RHO1
			#define RHP1
			#define RHR1
			#define RHM1
			#define RHI1
			#define RHN1
		// bottom row
			#define RBO1
			#define RBP1
			#define RBR1
			#define RBM1
			#define RBI1
			#define RBN1

	// thumbfan
		// 2 keys
			#define L1
			#define R1
		// 4 keys
			#define LN1
			#define LH1

			#define	RH1
			#define RN1

