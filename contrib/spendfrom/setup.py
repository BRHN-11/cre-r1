from distutils.core import setup
setup(name='corspendfrom',
      version='1.0',
      description='Command-line utility for cowrie "coin control"',
      author='Gavin Andresen',
      author_email='gavin@cowriefoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
