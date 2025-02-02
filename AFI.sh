#!/bin/bash

printf "n\np\n1\n\n\nw\n" | fdisk /dev/sda
mkfs.ext4 /dev/sda1
mount /dev/sda1 /mnt
pacstrap /mnt base linux
genfstab -U /mnt >>/mnt/etc/fstab
arch-chroot /mnt
ln -sf /usr/share/zoneinfo/America/Los_Angeles /etc/localtime
hwclock --systohc
locale-gen
echo 'LANG=en_US.UTF-8' >/etc/locale.conf
echo arch >/etc/hostname
pacman -Syu
pacman -S dhcpcd
systemctl enable dhcpcd
echo "root:123" | chpasswd
pacman -S grub
grub-install --target=i386-pc /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg
sh -c \"\$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)\"
chsh -s \$(which zsh)
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git \${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/themes/powerlevel10k
echo 'ZSH_THEME=\"powerlevel10k/powerlevel10k\"' >> ~/.zshrc
echo 'neofetch' >> ~/.zshrc
grub-mkconfig -o /boot/grub/grub.cfg


echo "AFL: done! u can reboot the system now"
