let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-23.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in

pkgs.mkShell {
  buildInputs = [
    pkgs.pkgsCross.avr.buildPackages.gcc
    pkgs.avrdude
    pkgs.gnumake
    pkgs.python311
    pkgs.poetry
  ];

  shellHook = ''
    export EMBEDDED_ROOT_DIR=$PWD
    export EMBEDDED_BUILD_DIR=$PWD/build
    export EMBEDDED_SRC_DIR=$PWD/src
    poetry install
    echo "Environment ready for Embedded Development."
  '';
}

