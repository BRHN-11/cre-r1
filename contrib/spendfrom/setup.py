from distutils.core import setup
setup(name='wzcspendfrom',
      version='1.0',
      description='Command-line utility for wuzhucoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@wuzhucoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
