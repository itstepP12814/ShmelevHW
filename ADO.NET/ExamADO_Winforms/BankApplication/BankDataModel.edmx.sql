
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 10/22/2015 17:43:45
-- Generated from EDMX file: D:\dev\ShmelevHW\ADO.NET\ExamADO_Winforms\BankApplication\BankDataModel.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [BankDataBase];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[FK_BankBankBranch]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[BankBranchSet] DROP CONSTRAINT [FK_BankBankBranch];
GO
IF OBJECT_ID(N'[dbo].[FK_BankBranchReviews]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[ReviewsSet] DROP CONSTRAINT [FK_BankBranchReviews];
GO
IF OBJECT_ID(N'[dbo].[FK_BankBranchServices]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[ServicesSet] DROP CONSTRAINT [FK_BankBranchServices];
GO
IF OBJECT_ID(N'[dbo].[FK_BankExchangeRates]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[ExchangeRatesSet] DROP CONSTRAINT [FK_BankExchangeRates];
GO

-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[BankBranchSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[BankBranchSet];
GO
IF OBJECT_ID(N'[dbo].[BankSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[BankSet];
GO
IF OBJECT_ID(N'[dbo].[ExchangeRatesSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[ExchangeRatesSet];
GO
IF OBJECT_ID(N'[dbo].[ReviewsSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[ReviewsSet];
GO
IF OBJECT_ID(N'[dbo].[ServicesNamesSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[ServicesNamesSet];
GO
IF OBJECT_ID(N'[dbo].[ServicesSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[ServicesSet];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'BankBranchSet'
CREATE TABLE [dbo].[BankBranchSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL,
    [PhoneNumber] nvarchar(max)  NULL,
    [Address] nvarchar(max)  NULL,
    [Xpos] float  NOT NULL,
    [Ypos] float  NOT NULL,
    [OpenDate] datetime  NULL,
    [WorkTime] nvarchar(max)  NULL,
    [BreakTime] nvarchar(max)  NULL,
    [Bank_Id] int  NOT NULL,
    [OperatorInfo] nvarchar(max)  NULL
);
GO

-- Creating table 'BankSet'
CREATE TABLE [dbo].[BankSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL
);
GO

-- Creating table 'ExchangeRatesSet'
CREATE TABLE [dbo].[ExchangeRatesSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Currency] nvarchar(max)  NOT NULL,
    [Sell] decimal(18,0)  NOT NULL,
    [Buy] decimal(18,0)  NOT NULL,
    [Bank_Id] int  NOT NULL,
    [XmlBankId] nvarchar(max)  NOT NULL
);
GO

-- Creating table 'ReviewsSet'
CREATE TABLE [dbo].[ReviewsSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Sender] nvarchar(max)  NOT NULL,
    [ReviewText] nvarchar(max)  NOT NULL,
    [Rating] int  NOT NULL,
    [BankBranch_Id] int  NOT NULL
);
GO

-- Creating table 'ServicesNamesSet'
CREATE TABLE [dbo].[ServicesNamesSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL
);
GO

-- Creating table 'ServicesSet'
CREATE TABLE [dbo].[ServicesSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL,
    [Description] nvarchar(max)  NULL,
    [BankBranch_Id] int  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [Id] in table 'BankBranchSet'
ALTER TABLE [dbo].[BankBranchSet]
ADD CONSTRAINT [PK_BankBranchSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'BankSet'
ALTER TABLE [dbo].[BankSet]
ADD CONSTRAINT [PK_BankSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'ExchangeRatesSet'
ALTER TABLE [dbo].[ExchangeRatesSet]
ADD CONSTRAINT [PK_ExchangeRatesSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'ReviewsSet'
ALTER TABLE [dbo].[ReviewsSet]
ADD CONSTRAINT [PK_ReviewsSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'ServicesNamesSet'
ALTER TABLE [dbo].[ServicesNamesSet]
ADD CONSTRAINT [PK_ServicesNamesSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'ServicesSet'
ALTER TABLE [dbo].[ServicesSet]
ADD CONSTRAINT [PK_ServicesSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [Bank_Id] in table 'BankBranchSet'
ALTER TABLE [dbo].[BankBranchSet]
ADD CONSTRAINT [FK_BankBankBranch]
    FOREIGN KEY ([Bank_Id])
    REFERENCES [dbo].[BankSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_BankBankBranch'
CREATE INDEX [IX_FK_BankBankBranch]
ON [dbo].[BankBranchSet]
    ([Bank_Id]);
GO

-- Creating foreign key on [BankBranch_Id] in table 'ReviewsSet'
ALTER TABLE [dbo].[ReviewsSet]
ADD CONSTRAINT [FK_BankBranchReviews]
    FOREIGN KEY ([BankBranch_Id])
    REFERENCES [dbo].[BankBranchSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_BankBranchReviews'
CREATE INDEX [IX_FK_BankBranchReviews]
ON [dbo].[ReviewsSet]
    ([BankBranch_Id]);
GO

-- Creating foreign key on [BankBranch_Id] in table 'ServicesSet'
ALTER TABLE [dbo].[ServicesSet]
ADD CONSTRAINT [FK_BankBranchServices]
    FOREIGN KEY ([BankBranch_Id])
    REFERENCES [dbo].[BankBranchSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_BankBranchServices'
CREATE INDEX [IX_FK_BankBranchServices]
ON [dbo].[ServicesSet]
    ([BankBranch_Id]);
GO

-- Creating foreign key on [Bank_Id] in table 'ExchangeRatesSet'
ALTER TABLE [dbo].[ExchangeRatesSet]
ADD CONSTRAINT [FK_BankExchangeRates]
    FOREIGN KEY ([Bank_Id])
    REFERENCES [dbo].[BankSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_BankExchangeRates'
CREATE INDEX [IX_FK_BankExchangeRates]
ON [dbo].[ExchangeRatesSet]
    ([Bank_Id]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------