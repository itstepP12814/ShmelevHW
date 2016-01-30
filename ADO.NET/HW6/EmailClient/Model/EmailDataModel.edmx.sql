
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 10/05/2015 09:44:00
-- Generated from EDMX file: D:\dev\ShmelevHW\ADO.NET\HW6\EmailClient\Model\EmailDataModel.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [EmailDataBase];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[FK_EmailUnitRecipient_EmailUnit]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[EmailUnitRecipient] DROP CONSTRAINT [FK_EmailUnitRecipient_EmailUnit];
GO
IF OBJECT_ID(N'[dbo].[FK_EmailUnitRecipient_Recipient]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[EmailUnitRecipient] DROP CONSTRAINT [FK_EmailUnitRecipient_Recipient];
GO
IF OBJECT_ID(N'[dbo].[FK_RecipientCategory]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[RecipientSet] DROP CONSTRAINT [FK_RecipientCategory];
GO

-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[RecipientSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[RecipientSet];
GO
IF OBJECT_ID(N'[dbo].[CategorySet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[CategorySet];
GO
IF OBJECT_ID(N'[dbo].[EmailUnitSet]', 'U') IS NOT NULL
    DROP TABLE [dbo].[EmailUnitSet];
GO
IF OBJECT_ID(N'[dbo].[EmailUnitRecipient]', 'U') IS NOT NULL
    DROP TABLE [dbo].[EmailUnitRecipient];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'RecipientSet'
CREATE TABLE [dbo].[RecipientSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL,
    [Email] nvarchar(max)  NOT NULL,
    [Category_Id] int  NOT NULL
);
GO

-- Creating table 'CategorySet'
CREATE TABLE [dbo].[CategorySet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL,
    [RightKey] int  NOT NULL,
    [LeftKey] int  NOT NULL,
    [Level] int  NOT NULL
);
GO

-- Creating table 'EmailUnitSet'
CREATE TABLE [dbo].[EmailUnitSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Text] nvarchar(max)  NOT NULL
);
GO

-- Creating table 'EmailUnitRecipient'
CREATE TABLE [dbo].[EmailUnitRecipient] (
    [EmailUnit_Id] int  NOT NULL,
    [Recipient_Id] int  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [Id] in table 'RecipientSet'
ALTER TABLE [dbo].[RecipientSet]
ADD CONSTRAINT [PK_RecipientSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'CategorySet'
ALTER TABLE [dbo].[CategorySet]
ADD CONSTRAINT [PK_CategorySet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'EmailUnitSet'
ALTER TABLE [dbo].[EmailUnitSet]
ADD CONSTRAINT [PK_EmailUnitSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [EmailUnit_Id], [Recipient_Id] in table 'EmailUnitRecipient'
ALTER TABLE [dbo].[EmailUnitRecipient]
ADD CONSTRAINT [PK_EmailUnitRecipient]
    PRIMARY KEY CLUSTERED ([EmailUnit_Id], [Recipient_Id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [EmailUnit_Id] in table 'EmailUnitRecipient'
ALTER TABLE [dbo].[EmailUnitRecipient]
ADD CONSTRAINT [FK_EmailUnitRecipient_EmailUnit]
    FOREIGN KEY ([EmailUnit_Id])
    REFERENCES [dbo].[EmailUnitSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [Recipient_Id] in table 'EmailUnitRecipient'
ALTER TABLE [dbo].[EmailUnitRecipient]
ADD CONSTRAINT [FK_EmailUnitRecipient_Recipient]
    FOREIGN KEY ([Recipient_Id])
    REFERENCES [dbo].[RecipientSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_EmailUnitRecipient_Recipient'
CREATE INDEX [IX_FK_EmailUnitRecipient_Recipient]
ON [dbo].[EmailUnitRecipient]
    ([Recipient_Id]);
GO

-- Creating foreign key on [Category_Id] in table 'RecipientSet'
ALTER TABLE [dbo].[RecipientSet]
ADD CONSTRAINT [FK_RecipientCategory]
    FOREIGN KEY ([Category_Id])
    REFERENCES [dbo].[CategorySet]
        ([Id])
    ON DELETE CASCADE ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_RecipientCategory'
CREATE INDEX [IX_FK_RecipientCategory]
ON [dbo].[RecipientSet]
    ([Category_Id]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------