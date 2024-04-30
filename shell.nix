{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.pkgsCross.avr.buildPackages.gcc
    pkgs.avrdude
    pkgs.gnumake
    pkgs.git
  ];

  shellHook = ''
    export EMBEDDED_ROOT_DIR=$PWD
    export EMBEDDED_BUILD_DIR=$PWD/build
    export EMBEDDED_SRC_DIR=$PWD/src
    echo "Environment ready for Embedded Development."
  '';
}

