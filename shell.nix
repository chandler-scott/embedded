{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.pkgsCross.avr.buildPackages.gcc
    pkgs.avrdude
    pkgs.gnumake
    pkgs.git
  ];

  shellHook = ''
    echo "Environment ready for Embedded Development."
  '';
}

