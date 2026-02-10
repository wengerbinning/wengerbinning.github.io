Ruby是一个专注于简单性与生产力的编程脚本



RubyGems是ruby的一个包管理工具。





Gem Bundle 通过跟踪和安装所需的精确 gem 和版本为 Ruby 项目提供一致的环境。




```Gemfiles
source 'https://rubygems.org'
gem 'nokogiri'
gem 'rack', '~> 2.2.4'
gem 'rspec'
```

```shell
bundle install
```


mariadb-install-db --user=mysql --basedir=/usr --datadir=/db/mariadb