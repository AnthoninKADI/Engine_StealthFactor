# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/focal64"

  config.vm.synced_folder "StealthFactor", "/project"

  config.vm.provider :virtualbox do |vb|
    vb.name = "Courses - Architecture"
  end

  config.vm.provision "shell", inline: <<-SHELL
    apt-get update
    apt-get install -y g++ g++-multilib libode-dev libsfml-dev make
  SHELL
end
