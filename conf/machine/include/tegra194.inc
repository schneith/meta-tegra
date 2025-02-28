# Settings common to all Xavier (tegra194) SoCs

SOC_FAMILY = "tegra194"

require conf/machine/include/soc-family.inc
DEFAULTTUNE ?= "armv8a-crc"
require conf/machine/include/arm/arch-armv8-2a.inc

INITRAMFS_IMAGE ?= "tegra-minimal-initramfs"
INITRAMFS_IMAGE_BUNDLE ?= "1"
IMAGE_UBOOT ?= ""
INITRAMFS_FSTYPES_append = "${@'' if d.getVar('INITRAMFS_IMAGE_BUNDLE') == '1' else ' cpio.gz.cboot cpio.gz.cboot.bup-payload'}"

TEGRA_AUDIO_DEVICE ?= "tegrahdat194ref"

SERIAL_CONSOLES ?= "115200;ttyTCU0"

KERNEL_MODULE_AUTOLOAD = "nvgpu"

NVIDIA_CHIP = "0x19"

TEGRA_BOARDID ?= "2888"
TEGRA_FAB ?= "400"
TEGRA_BOARDSKU ?= "0001"
TEGRA_BOARDREV ?= "H.0"
TEGRA_CHIPREV ?= "2"
TEGRA_MINRATCHET_CONFIG ?= "tegra194-mb1-bct-ratchet-p2888-0000-p2822-0000.cfg"
# Extracted from l4t_generate_soc_bup.sh for BOARDID=2888 and board=jetson-agx-xavier-devkit
TEGRA_BUPGEN_SPECS ?= "fab=400;boardsku=0001;boardrev=H.0 \
                       fab=400;boardsku=0001;boardrev=J.0 \
                       fab=400;boardsku=0001;boardrev=L.0 \
                       fab=400;boardsku=0004;boardrev="

TEGRA_SIGNING_ENV = "CHIPREV=${TEGRA_CHIPREV} BOARDID=${TEGRA_BOARDID} FAB=${TEGRA_FAB} BOARDSKU=${TEGRA_BOARDSKU} BOARDREV=${TEGRA_BOARDREV}"

CUDA_NVCC_ARCH_FLAGS ?= "--gpu-architecture=compute_72 --gpu-code=sm_72"

PREFERRED_PROVIDER_virtual/bootloader ?= "cboot-t19x"
PREFERRED_PROVIDER_tos-trusty ?= "tos-prebuilt"

UBOOT_EXTLINUX ?= ""
UBOOT_EXTLINUX_KERNEL_IMAGE ?= "/boot/${KERNEL_IMAGETYPE}"
UBOOT_EXTLINUX_INITRD ?= "${@'/boot/initrd' if d.getVar('INITRAMFS_IMAGE') != '' and d.getVar('INITRAMFS_IMAGE_BUNDLE') != '1' else ''}"
# This is inserted into UBOOT_EXTLINUX_ROOT in tegra-common.inc
KERNEL_ROOTSPEC ?= "rootwait"
UBOOT_EXTLINUX_KERNEL_ARGS ?= ""

require conf/machine/include/tegra-common.inc

L4T_BSP_NAME = "T186"
L4T_SRCS_NAME = "sources/T186"
L4T_BSP_PREFIX = "Jetson"
L4T_DEB_SOCNAME = "t194"

NVPMODEL ?= "nvpmodel_t194"
