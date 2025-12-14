{
  description = "QMK firmware flake with appdirs in the dev shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.05";
    flake-utils.url = "github:numtide/flake-utils";
    qmk-nix-utils.url = "github:aciceri/qmk-nix-utils";
  };

  outputs = { self, nixpkgs, flake-utils, qmk-nix-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        pythonEnv = pkgs.python3.withPackages (ps: [ ps.appdirs ]);

        qmkUtils = qmk-nix-utils.utils-factory {
          src = ./firmware;          # put your keyboard sources here
          keyboard-name = "mykb";    # matches keyboards/mykb in QMK
          keymap-name = "default";   # e.g. keyboards/mykb/keymaps/default
          extra-build-inputs = [ pythonEnv ];
          flash-script = ''
            echo -n "Press RESET on the controller..."
            while [ ! -e /dev/ttyACM0 ]; do
              sleep 0.5
            done
            ${pkgs.avrdude}/bin/avrdude \
              -p atmega32u4 -c avr109 -P /dev/ttyACM0 -U flash:w:$HEX_FILE
          '';
        };
      in
      {
        packages.default = qmkUtils.hex;

        # `nix run .#flash`
        apps.flash = {
          type = "app";
          program = "${qmkUtils.flasher}/bin/flasher";
        };

        devShells.default = pkgs.mkShell {
          buildInputs = [
            pkgs.qmk        # gives you the familiar `qmk` command
            pythonEnv
          ];
          shellHook = ''
            echo "QMK + appdirs shell ready"
          '';
        };
      });
}
